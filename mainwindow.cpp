#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QPrinter>
#include <QPainter>

#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_series_data.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_text.h>
#include <qwt_math.h>
#include <qwt_polar_renderer.h>

#include <qwt_polar_plot.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {    
    QwtPolarPlot *p = new QwtPolarPlot(this);

    ui->setupUi(this);

    /*ViStatus status;
    ViObject obj;
    static ViSession defaultRM, instr;
    char outputBuffer[VI_FIND_BUFLEN];
    ViUInt32 count;
    ViUInt16 portNo;

    status = viOpenDefaultRM(&defaultRM);
    if (status < VI_SUCCESS)  {
        qDebug() << "Could not open a session to the VISA Resource Manager!";
        return;
    }

    status = viOpen(defaultRM, "TCPIP0::10.10.10.124::inst0::INSTR", VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)   {
        qDebug() << "An error occurred opening the session to TCPIP0::ftp.ni.com::21::SOCKET\n";
        viClose(defaultRM);
        return;
    }

    viSetAttribute(instr, VI_ATTR_TCPIP_NODELAY, VI_TRUE);

    snprintf(outputBuffer, 6, "*IDN?\n");
    status = viWrite(instr, (ViBuf)outputBuffer, 6, &count);

    status = viRead(instr, (ViBuf)outputBuffer, 25, &count);
    if (status < VI_SUCCESS)  {
        qDebug() << "viRead failed with error code: \n" << status;
        viClose(defaultRM);
        return;
    }

    qDebug() << QString().sprintf("The server response is:\n %s\n\n",outputBuffer);
    status = viGetAttribute (instr, VI_ATTR_TCPIP_ADDR, outputBuffer);
    qDebug() << QString().sprintf(" Address:  %s\n",outputBuffer);

    status = viGetAttribute(instr, VI_ATTR_TCPIP_HOSTNAME, outputBuffer);
    qDebug() << QString().sprintf(" Host Name:  %s\n",outputBuffer);

    status = viGetAttribute(instr, VI_ATTR_TCPIP_PORT, &portNo);
    qDebug() << QString().sprintf(" Port:  %d\n",portNo);

    status = viGetAttribute(instr, VI_ATTR_RSRC_CLASS, outputBuffer);
    qDebug() << QString().sprintf(" Resource Class:  %s\n",outputBuffer);

    viClose (instr);
    viClose (defaultRM);

    QwtPlot p;
    QwtPolarPlot pp;
    pp.adjustSize();*/

    ui->propertyEditor->setObject(&measurementSettings);

    loadSettings();
}

void MainWindow::saveSettings() {
    QSettings settings("Liewenthal Electronics Ltd.", "RotaryMeasure");

    for(int i = 0; i < measurementSettings.metaObject()->propertyCount(); i++)
        settings.setValue(measurementSettings.metaObject()->property(i).name(), measurementSettings.property(measurementSettings.metaObject()->property(i).name()));
}

void MainWindow::loadSettings() {
    QSettings settings("Liewenthal Electronics Ltd.", "RotaryMeasure");

    for(int i = 0; i < measurementSettings.metaObject()->propertyCount(); i++)
        measurementSettings.setProperty(measurementSettings.metaObject()->property(i).name(), settings.value(measurementSettings.metaObject()->property(i).name(), measurementSettings.property(measurementSettings.metaObject()->property(i).name())));
}

void MainWindow::closeEvent(QCloseEvent *event) {
    saveSettings();
    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionMeasure_triggered() {
    RohdeSchwarzZVL6 instrument;
    instrument.init();
    instrument.open("TCPIP0::10.10.10.134::inst0::INSTR");
    instrument.write("*IDN?\n");
    qDebug() << instrument.read();

    instrument.initMeasurement(measurementSettings);

    qDebug() << instrument.readMeasurement();

    instrument.close();
}

void MainWindow::newMeasurementValue(qreal value) {
    qDebug() << ((Data*)ui->widget->curve->data())->data.size();
    ((Data*)ui->widget->curve->data())->addPoint(QwtPointPolar(((Data*)ui->widget->curve->data())->data.size(), value));
    ui->widget->replot();
}

void MainWindow::on_actionStartTest_triggered() {
   /*RohdeSchwarzZVL6 *instrument = new RohdeSchwarzZVL6();
    instrument->init();
    instrument->open("TCPIP0::10.10.10.124::inst0::INSTR");

    instrument->initMeasurement(measurementSettings);

    RandomData *instrument = new RandomData();

    measureThread = new MeasureThread();
    measureThread->instrument = 0;
    measureThread->data = (Data*)ui->widget->curve->data();
    connect(measureThread, SIGNAL(newValue(qreal)), this, SLOT(newMeasurementValue(qreal)));
    measureThread->start();*/

    // some random data incase we do not have the instrument...
    for(int i=0;i<300;i++){
        qreal r = 1;
        if(((Data*)ui->widget->curve->data())->data.size() > 1) r = ((Data*)ui->widget->curve->data())->data.last().radius() + (((qrand() % 10) - 6) / 10.0);
        if(r < 1) r = 1;
        ((Data*)ui->widget->curve->data())->addPoint(QwtPointPolar(((Data*)ui->widget->curve->data())->data.size(), r));
    }

    ui->widget->replot();
}

void MainWindow::on_actionStopTest_triggered() {
    if(measureThread) {
        measureThread->abort();
        if(measureThread->instrument)
        measureThread->instrument->close();
    }
}

#define pi 3.14159265358979
void MainWindow::on_actionDebugGenerateSampleData_triggered() {
    qreal r = -96, t;
    for(int i = 0; i < 360; i++) {
        t = (i * pi) / 180.0;
        r = ((sin(t)*qSqrt(qAbs(cos(t))))/(sin(t)+(7.0/5.0)))-(2*sin(t))+2;
        //r = 1 - sin((i * pi)/180);
        ((Data*)ui->widget->curve->data())->addPoint(QwtPointPolar(i, r));
    }
    ui->widget->replot();
}

void MainWindow::on_actionExportToPdf_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("PDF File (*.pdf)"));
    if(fileName.isNull()) return;

    QPainter p;
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    p.begin(&printer);
    p.save();

    QTextDocument document;

    // TODO: add measurement data here
    // TODO: figure out what the report format should be...
    document.setHtml("<h1>Measurement 1</h1>\n<table border=\"1\"><tr><td>DATA 1</td><td>DATA 2</td></tr></table>");
    //document.print(&printer);
    document.drawContents(&p);

    QwtPolarRenderer plotRenderer;

    QRectF plotRect;
    plotRect.setWidth(printer.paperRect().width() * 0.8);
    plotRect.setHeight(plotRect.width());

    p.translate((printer.paperRect().width() * 0.1) * 0.95, (printer.paperRect().height() - plotRect.width()) * 0.80);
    plotRenderer.render(ui->widget, &p, plotRect);
    p.end();
}
