#include "plot.h"

#include <QtCore>
#include <QPen>

#include <qwt_polar_picker.h>
#include <qwt_polar_panner.h>
#include <qwt_picker_machine.h>
#include <qwt_polar_magnifier.h>

const QwtInterval radialInterval(0.0, 10.0);
const QwtInterval azimuthInterval(0.0, 360.0);

class MyPicker: public QwtPolarPicker
{
public:
    MyPicker( QwtPolarCanvas *canvas ):
        QwtPolarPicker( canvas )
    {
        setStateMachine( new QwtPickerDragPointMachine() );
        setRubberBand( QwtPicker::NoRubberBand );
        setTrackerMode( ActiveOnly );
    }

    virtual QwtText trackerTextPolar( const QwtPointPolar &pos ) const
    {
        QColor bg( Qt::white );
        bg.setAlpha( 200 );

        QwtText text = QwtPolarPicker::trackerTextPolar( pos );
        text.setBackgroundBrush( QBrush( bg ) );
        return text;
    }
};

Plot::Plot(QWidget *parent): QwtPolarPlot(parent) {
    d_grid = new QwtPolarGrid();
    d_grid->setPen( QPen( Qt::black ) );
    for(int scaleId = 0; scaleId < QwtPolar::ScaleCount; scaleId++) {
        d_grid->showGrid( scaleId );
        d_grid->showMinorGrid( scaleId );

        QPen minorPen( Qt::gray );

        d_grid->setMinorGridPen( scaleId, minorPen );
    }
    d_grid->setAxisPen( QwtPolar::AxisAzimuth, QPen( Qt::black ) );

    d_grid->showAxis(QwtPolar::AxisAzimuth, true);
    d_grid->showAxis(QwtPolar::AxisLeft, false);
    d_grid->showAxis(QwtPolar::AxisRight, true);
    d_grid->showAxis(QwtPolar::AxisTop, true);
    d_grid->showAxis(QwtPolar::AxisBottom, false);
    d_grid->showGrid(QwtPolar::Azimuth, true);
    d_grid->showGrid(QwtPolar::Radius, true);
    d_grid->attach(this);

    QwtPolarPicker *picker = new MyPicker(canvas());
    picker->setMousePattern(QwtEventPattern::MouseSelect1, Qt::RightButton);

    QwtPolarMagnifier *magnifier = new QwtPolarMagnifier(canvas());
    magnifier->setMouseButton(Qt::RightButton, Qt::ShiftModifier);

    new QwtPolarPanner(canvas());

    QwtLegend *legend = new QwtLegend;
    insertLegend( legend,  QwtPolarPlot::BottomLegend);
    curve = new QwtPolarCurve();
    curve->setTitle("Measurement 1");
    curve->setPen(QPen(Qt::blue, 2));
    Data* data = new Data(radialInterval, azimuthInterval, 100);

    curve->setData(data);
    curve->attach(this);
}
