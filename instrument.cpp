#include "instrument.h"

QList<QByteArray> split(const QByteArray &needle, const QByteArray &haystack) {
    QList<QByteArray> result;
    int pos = -1, lastpos = 0;

    while((pos = haystack.indexOf(needle, lastpos)) != -1) {
        result << haystack.mid(lastpos, pos-lastpos);
        lastpos = pos+needle.length();
    }

    result<<haystack.right(haystack.length() - lastpos);
    return result;
}

qreal parse(const QByteArray &s) {
    QList<QByteArray> data = split("\n", s);
    qreal result = 0;
    bool ok = false;

    if(data.size() > 0) result = data.at(0).toDouble(&ok);

    if(!ok) result = 0;

    return result;
}

void Instrument::init() {
    status = viOpenDefaultRM(&defaultRM);
    if (status < VI_SUCCESS)  {
        qDebug() << "Could not open a session to the VISA Resource Manager!";
    }
}

void Instrument::open(QString connectionString) {
    status = viOpen(defaultRM, connectionString.toLocal8Bit().data(), VI_NULL, VI_NULL, &instrument);
    if (status < VI_SUCCESS)   {
        qDebug() << "An error occurred opening the session to " << connectionString << status;
        viClose(defaultRM);
        return;
    }
}

void Instrument::close() {
    viClose(defaultRM);
    viClose(instrument);
}

// todo write in chunks of VI_FIND_BUFLEN
void Instrument::write(QString string) {
    ViUInt32 count;
    status = viWrite(instrument, (ViBuf)string.toLocal8Bit().data(), string.size(), &count);
    if (status < VI_SUCCESS)  {
        qDebug() << "viWrite failed with error code: \n" << status;
    }
}

QByteArray Instrument::read() {
    QByteArray result;
    char outputBuffer[VI_FIND_BUFLEN];
    ViUInt32 count;
    do {
        status = viRead(instrument, (ViBuf)outputBuffer, VI_FIND_BUFLEN, &count);
        if (status < VI_SUCCESS)  {
            qDebug() << "viRead failed with error code: \n" << status;
            break;
        } else {
            result.append(outputBuffer, count);
        }
    } while(false/*count > 0*/);

    return result;
}

void RohdeSchwarzZVL6::initMeasurement(const MeasurementSettings& ms) {
    measurementSettings.copyFrom(ms);

    write("@REM; *RST; *CLS; :INST:SEL SAN;\n");
    write("TRIG:SOUR IMM; :INIT:CONT OFF; :SYST:DISP:UPD ON;\n");

    write(QString("FREQUENCY:CENTER %1 %2;\n").arg(measurementSettings.centerFrequency()).arg(measurementSettings.centerFrequencyUnit()));
    write(QString("FREQUENCY:SPAN %1 %2;\n").arg(measurementSettings.span()).arg(measurementSettings.spanUnit()));
    write(QString("SWE:TIME %1 %2;\n").arg(measurementSettings.sweepTime()).arg(measurementSettings.sweepTimeUnit()));
    write(QString("SWE:COUN %1;\n").arg(measurementSettings.sweepCount()));
    write(QString("SWE:POIN %1;\n").arg(measurementSettings.sweepPoints()));

    write(QString("DISP:TRAC:MODE %1;\n").arg(measurementSettings.traceMode()));
    write(QString("UNIT:POW %1;\n").arg(measurementSettings.unit()));
    write(QString("BAND:RES %1 %2;\n").arg(measurementSettings.resolutionBandwidth()).arg(measurementSettings.resolutionBandwidthUnit()));

    if(measurementSettings.span() == 0) {
        write("INIT:CONT OFF;\n");
        write("SENS:FREQ:MODE CW;\n");
        write("CALC:MARK:FUNC:SUMM:MEAN ON;\n");
        write("CALC:MARK:FUNC:SUMM:AVER ON;\n");
        write("INIT:CONT OFF;\n");
        write(QString("AVER:COUN %1;\n").arg(measurementSettings.averageCount()));
    }
}

QList<qreal> RohdeSchwarzZVL6::readMeasurement() {
    QList<qreal> result;
    if(measurementSettings.span() == 0) {
        write(":INIT:IMM; *WAI; :CALC:MARK:FUNC:SUMM:MEAN:AVER:RES?;\n");
        result << parse(read());
    } else {
        write(":INIT:IMM; *WAI; CALC:MARK:MAX; *WAI; CALC:MARK:Y?;\n");
        result << parse(read());

        write("*WAI; CALC:MARK:X?;\n");
        result << parse(read());
    }

    return result;
}


QList<qreal> RandomData::readMeasurement() {
    /*qreal r = 1;
    if(((Data*)ui->widget->curve->data())->data.size() > 1) r = ((Data*)ui->widget->curve->data())->data.last().radius() + (((qrand() % 10) - 6) / 10.0);
    //if(r < 1) r = 1;
    ((Data*)ui->widget->curve->data())->addPoint(QwtPointPolar(((Data*)ui->widget->curve->data())->data.size(), r));
    ui->widget->replot();*/
    return QList<qreal>() << (qrand() % 10) << (qrand() % 10);
}

void RandomData::initMeasurement(const MeasurementSettings &ms) {
}
