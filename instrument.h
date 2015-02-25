#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <visa.h>
#include <QtCore>

class MeasurementSettings: public QObject {
    Q_OBJECT

    Q_PROPERTY(QString CenterFrequencyUnit READ centerFrequencyUnit WRITE setCenterFrequencyUnit DESIGNABLE true USER true)
    Q_PROPERTY(qreal CenterFrequency READ centerFrequency WRITE setCenterFrequency DESIGNABLE true USER true)
    Q_CLASSINFO("CenterFrequency", "minimum=0;decimals=10;")

    Q_PROPERTY(QString SpanUnit READ spanUnit WRITE setSpanUnit DESIGNABLE true USER true)
    Q_PROPERTY(qreal Span READ span WRITE setSpan DESIGNABLE true USER true)

    Q_PROPERTY(QString SweepTimeUnit READ sweepTimeUnit WRITE setSweepTimeUnit DESIGNABLE true USER true)
    Q_PROPERTY(qreal Sweep READ sweepTime WRITE setSweep DESIGNABLE true USER true)

    Q_PROPERTY(quint32 SweepCount READ sweepCount WRITE setSweepCount DESIGNABLE true USER true)
    Q_PROPERTY(quint32 SweepPoints READ sweepPoints WRITE setSweepPoints DESIGNABLE true USER true)

    Q_PROPERTY(QString TraceMode READ traceMode WRITE setTraceMode DESIGNABLE true USER true)

    Q_PROPERTY(QString Unit READ unit WRITE setUnit DESIGNABLE true USER true)
    Q_PROPERTY(qreal ReferenceLevel READ referenceLevel WRITE setReferenceLevel DESIGNABLE true USER true)

    Q_PROPERTY(quint32 AverageCount READ averageCount WRITE setAverageCount DESIGNABLE true USER true)

    Q_PROPERTY(QString ResolutionBandwidthUnit READ resolutionBandwidthUnit WRITE setResolutionBandwidthUnit DESIGNABLE true USER true)
    Q_PROPERTY(qreal ResolutionBandwidth READ resolutionBandwidth WRITE setResolutionBandwidth DESIGNABLE true USER true)

private:
    QString m_CenterFrequencyUnit;
    qreal m_CenterFrequency;
    QString m_SpanUnit;
    qreal m_Span;
    QString m_SweepTimeUnit;
    qreal m_Sweep;
    quint32 m_SweepCount;
    quint32 m_SweepPoints;
    QString m_TraceMode;
    QString m_Unit;
    qreal m_ReferenceLevel;
    QString m_ResolutionBandwidthUnit;
    qreal m_ResolutionBandwidth;
    quint32 m_AverageCount;

public:
    explicit MeasurementSettings(): m_CenterFrequencyUnit(""), m_CenterFrequency(0), m_SpanUnit(""), m_Span(0), m_SweepTimeUnit(""), m_Sweep(0), m_SweepCount(0), m_SweepPoints(0), m_TraceMode(""), m_Unit(""), m_ReferenceLevel(0), m_ResolutionBandwidthUnit(""), m_ResolutionBandwidth(0) {
    }

    explicit MeasurementSettings(const QString &m_CenterFrequencyUnit, const qreal &m_CenterFrequency, const QString &m_SpanUnit, const qreal &m_Span, const QString &m_SweepTimeUnit, const qreal &m_Sweep, const quint32 &m_SweepCount, const quint32 &m_SweepPoints, const QString &m_TraceMode, const QString &m_Unit, const qreal &m_ReferenceLevel, const QString &m_ResolutionBandwidthUnit, const qreal &m_ResolutionBandwidth): m_CenterFrequencyUnit(m_CenterFrequencyUnit), m_CenterFrequency(m_CenterFrequency), m_SpanUnit(m_SpanUnit), m_Span(m_Span), m_SweepTimeUnit(m_SweepTimeUnit), m_Sweep(m_Sweep), m_SweepCount(m_SweepCount), m_SweepPoints(m_SweepPoints), m_TraceMode(m_TraceMode), m_Unit(m_Unit), m_ReferenceLevel(m_ReferenceLevel), m_ResolutionBandwidthUnit(m_ResolutionBandwidthUnit), m_ResolutionBandwidth(m_ResolutionBandwidth) {
    }

    void copyFrom(const MeasurementSettings &measurementSettings) {
        for(int i = 0; i < metaObject()->propertyCount(); i++)
            setProperty(metaObject()->property(i).name(), measurementSettings.property(measurementSettings.metaObject()->property(i).name()));
    }

    QString centerFrequencyUnit() const  {
        return m_CenterFrequencyUnit;
    }
    qreal centerFrequency() const  {
        return m_CenterFrequency;
    }

    QString spanUnit() const  {
        return m_SpanUnit;
    }

    qreal span() const {
        return m_Span;
    }

    QString sweepTimeUnit() const {
        return m_SweepTimeUnit;
    }

    qreal sweepTime() const {
        return m_Sweep;
    }

    quint32 sweepCount() const {
        return m_SweepCount;
    }

    quint32 sweepPoints() const {
        return m_SweepPoints;
    }

    QString traceMode() const {
        return m_TraceMode;
    }

    QString unit() const {
        return m_Unit;
    }

    qreal referenceLevel() const {
        return m_ReferenceLevel;
    }

    QString resolutionBandwidthUnit() const {
        return m_ResolutionBandwidthUnit;
    }

    qreal resolutionBandwidth() const {
        return m_ResolutionBandwidth;
    }

    quint32 averageCount() const  {
        return m_AverageCount;
    }

public slots:
    void setCenterFrequencyUnit(QString arg)  {
        m_CenterFrequencyUnit = arg;
    }

    void setCenterFrequency(qreal arg) {
        m_CenterFrequency = arg;
    }

    void setSpanUnit(QString arg) {
        m_SpanUnit = arg;
    }

    void setSpan(qreal arg) {
        m_Span = arg;
    }

    void setSweepTimeUnit(QString arg) {
        m_SweepTimeUnit = arg;
    }

    void setSweep(qreal arg)  {
        m_Sweep = arg;
    }

    void setSweepCount(quint32 arg) {
        m_SweepCount = arg;
    }

    void setSweepPoints(quint32 arg) {
        m_SweepPoints = arg;
    }

    void setTraceMode(QString arg) {
        m_TraceMode = arg;
    }

    void setUnit(QString arg)  {
        m_Unit = arg;
    }

    void setReferenceLevel(qreal arg) {
        m_ReferenceLevel = arg;
    }

    void setResolutionBandwidthUnit(QString arg) {
        m_ResolutionBandwidthUnit = arg;
    }

    void setResolutionBandwidth(qreal arg) {
        m_ResolutionBandwidth = arg;
    }

    void setAverageCount(quint32 arg) {
        m_AverageCount = arg;
    }
};

class Instrument {
public:
    ViSession instrument, defaultRM;
    ViStatus status;
    QByteArray read();
    void write(QString string);
    void close();
    void open(QString connectionString);
    void init();
};

class RohdeSchwarzZVL6: public Instrument {
  public:
    MeasurementSettings measurementSettings;
    QList<qreal> readMeasurement();
    void initMeasurement(const MeasurementSettings &ms);
};

class RandomData: public RohdeSchwarzZVL6 {

public:
  MeasurementSettings measurementSettings;
  QList<qreal> readMeasurement();
  void initMeasurement(const MeasurementSettings &ms);
};

#endif // INSTRUMENT_H
