#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMetaProperty>
#include <QThread>

#include <plot.h>

#include "instrument.h"

#define d2r(d) ((((qreal)d)*((qreal)3.14159265358979323))/((qreal)180))

class MeasureThread : public QThread {
    Q_OBJECT
public:
    RohdeSchwarzZVL6 *instrument;
    Data* data;
    qreal last;
    int n;
protected:
    bool stop;
    void run() {
        last = 0;
        n = 0;
        stop = false;
        while(!stop) {
            QList<qreal> vs;// = instrument->readMeasurement();
            qreal r = 1;
            r = qSin(qPow(2, d2r(n)));

            vs << r;
            vs << n++;

            if(vs.size() > 0) {
                emit newValue(vs.at(0));
            }

            usleep(10);
        }
    }
public:
    void abort() {
        stop = true;
    }
Q_SIGNALS:
    void newValue(const qreal &value);
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    MeasurementSettings measurementSettings;
    MeasureThread *measureThread;
    void loadSettings();
    void saveSettings();
    void closeEvent(QCloseEvent *event);
private slots:
    void on_actionMeasure_triggered();

    void on_actionStartTest_triggered();

    void on_actionStopTest_triggered();
    void newMeasurementValue(qreal value);

    void on_actionDebugGenerateSampleData_triggered();

    void on_actionExportToPdf_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
