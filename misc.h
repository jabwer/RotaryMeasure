#ifndef MISC_H
#define MISC_H

#include <QtCore>

class ProjectSettings: public QObject {
    Q_OBJECT

    Q_PROPERTY(QString ProjectName READ projectName WRITE setProjectName DESIGNABLE true USER true)
    Q_PROPERTY(QString DutDescription READ dutDescription WRITE setDutDescription DESIGNABLE true USER true)
    Q_PROPERTY(QString Polarization READ polarization WRITE setPolarization DESIGNABLE true USER true)
    Q_PROPERTY(QString Comments READ comments WRITE setComments DESIGNABLE true USER true)
    Q_PROPERTY(QString OperatorsName READ operatorsName WRITE setOperatorsName DESIGNABLE true USER true)

public:

    QString projectName() const
    {
        return m_ProjectName;
    }

    QString dutDescription() const
    {
        return m_DutDescription;
    }

    QString polarization() const
    {
        return m_Polarization;
    }

    QString comments() const
    {
        return m_Comments;
    }

    QString OperatorsName() const
    {
        return m_OperatorsName;
    }

    QString operatorsName() const
    {
        return m_OperatorsName;
    }

public slots:
    void setProjectName(QString arg)
    {
        m_ProjectName = arg;
    }

    void setDutDescription(QString arg)
    {
        m_DutDescription = arg;
    }

    void setPolarization(QString arg)
    {
        m_Polarization = arg;
    }

    void setComments(QString arg)
    {
        m_Comments = arg;
    }

    void setOperatorsName(QString arg)
    {
        m_OperatorsName = arg;
    }

private:

    QString m_ProjectName;
    QString m_DutDescription;
    QString m_Polarization;
    QString m_Comments;
    QString m_OperatorsName;
};

class TurntableSettings: public QObject {
    Q_OBJECT

    Q_PROPERTY(QString Port READ port WRITE setPort DESIGNABLE true USER true)
    Q_PROPERTY(qint32 BaudRate READ baudRate WRITE setBaudRate DESIGNABLE true USER true)
    Q_PROPERTY(qint32 StepsPerDegree READ stepsPerDegree WRITE setStepsPerDegree DESIGNABLE true USER true)
    Q_PROPERTY(QString DiskSpeed READ DiskSpeed WRITE setDiskSpeed DESIGNABLE true USER true)
    Q_PROPERTY(QString DiskToZeroSpeed READ diskToZeroSpeed WRITE setDiskToZeroSpeed DESIGNABLE true USER true)
    Q_PROPERTY(QString Acceleration READ acceleration WRITE setAcceleration DESIGNABLE true USER true)
    Q_PROPERTY(QString Deceleration READ deceleration WRITE setDeceleration DESIGNABLE true USER true)
    Q_PROPERTY(bool LimitTo360Degrees READ limitTo360Degrees WRITE setLimitTo360Degrees DESIGNABLE true USER true)
public:


    QString port() const
    {
        return m_Port;
    }

    qint32 baudRate() const
    {
        return m_BaudRate;
    }

    qint32 stepsPerDegree() const
    {
        return m_StepsPerDegree;
    }

    QString DiskSpeed() const
    {
        return m_DiskSpeed;
    }

    QString diskToZeroSpeed() const
    {
        return m_DiskToZeroSpeed;
    }

    QString acceleration() const
    {
        return m_Acceleration;
    }

    QString deceleration() const
    {
        return m_Deceleration;
    }

    bool limitTo360Degrees() const
    {
        return m_LimitTo360Degrees;
    }

public slots:


    void setPort(QString arg)
    {
        m_Port = arg;
    }

    void setBaudRate(qint32 arg)
    {
        m_BaudRate = arg;
    }

    void setStepsPerDegree(qint32 arg)
    {
        m_StepsPerDegree = arg;
    }

    void setDiskSpeed(QString arg)
    {
        m_DiskSpeed = arg;
    }

    void setDiskToZeroSpeed(QString arg)
    {
        m_DiskToZeroSpeed = arg;
    }

    void setAcceleration(QString arg)
    {
        m_Acceleration = arg;
    }

    void setDeceleration(QString arg)
    {
        m_Deceleration = arg;
    }

    void setLimitTo360Degrees(bool arg)
    {
        m_LimitTo360Degrees = arg;
    }

private:

    QString m_Port;
    qint32 m_BaudRate;
    qint32 m_StepsPerDegree;
    QString m_DiskSpeed;
    QString m_DiskToZeroSpeed;
    QString m_Acceleration;
    QString m_Deceleration;
    bool m_LimitTo360Degrees;
};

#endif // MISC_H
