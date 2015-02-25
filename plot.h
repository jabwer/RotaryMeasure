#ifndef PLOT_H
#define PLOT_H

#include <QtWidgets/QtWidgets>
#include <qwt_polar_plot.h>
#include <qwt_polar_grid.h>
#include <qwt_legend.h>
#include <qwt_polar_curve.h>

class Data: public QwtSeriesData<QwtPointPolar> {
public:
    QList<QwtPointPolar> data;
    QRectF rect;
    Data(const QwtInterval &radialInterval, const QwtInterval &azimuthInterval, size_t size): d_radialInterval(radialInterval),  d_azimuthInterval(azimuthInterval), d_size(size)  {
    }

    virtual size_t size() const {
        return data.size();
    }

    void addPoint(const QwtPointPolar &p) {
        /*if(data.size() < 1) {
            minP = p;
            maxP = p;
        } else {
            if(minP.radius() > p.radius()) minP = p;
            if(maxP.radius() < p.radius()) maxP = p;
        }*/

        if(data.size() < 1) {
            rect.setRect( p.radius(), p.radius(), 0.0, 0.0 );
        } else {
            if(rect.bottom() < p.radius()) rect.setBottom(p.radius());
            if(rect.top() > p.radius()) rect.setTop(p.radius());
        }
        data.append(p);
    }

    virtual QwtPointPolar sample(size_t i) const  {
        return data.at(i);
    }

    virtual QRectF boundingRect() const {
        return rect;
        if (d_boundingRect.width() < 0.0)
            d_boundingRect = qwtBoundingRect(*this);
        qreal min = qMin(minP.radius(), maxP.radius()), max = qMax(minP.radius(), maxP.radius());
        if(min < 0 && max > 0) {
            max = qMax(qAbs(min), max);
        }

        //min = -5; max = 5;
        return QRectF(min, min, max, max);
    }

protected:
    QwtInterval d_radialInterval;
    QwtInterval d_azimuthInterval;
    size_t d_size;
    QwtPointPolar minP, maxP;
};

class Plot : public QwtPolarPlot
{
    Q_OBJECT
public:
    QwtPolarGrid *d_grid;
    QwtPolarCurve *curve;
    explicit Plot(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PLOT_H
