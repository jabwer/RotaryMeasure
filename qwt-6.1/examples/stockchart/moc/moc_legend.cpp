/****************************************************************************
** Meta object code from reading C++ file 'legend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../legend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'legend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Legend_t {
    QByteArrayData data[10];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Legend_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Legend_t qt_meta_stringdata_Legend = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 7),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 12),
QT_MOC_LITERAL(4, 29, 8),
QT_MOC_LITERAL(5, 38, 2),
QT_MOC_LITERAL(6, 41, 5),
QT_MOC_LITERAL(7, 47, 12),
QT_MOC_LITERAL(8, 60, 20),
QT_MOC_LITERAL(9, 81, 11)
    },
    "Legend\0checked\0\0QwtPlotItem*\0plotItem\0"
    "on\0index\0updateLegend\0QList<QwtLegendData>\0"
    "handleClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Legend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    2,   36,    2, 0x0a,
       9,    1,   41,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, 0x80000000 | 8,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void Legend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Legend *_t = static_cast<Legend *>(_o);
        switch (_id) {
        case 0: _t->checked((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->updateLegend((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QList<QwtLegendData>(*)>(_a[2]))); break;
        case 2: _t->handleClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Legend::*_t)(QwtPlotItem * , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Legend::checked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Legend::staticMetaObject = {
    { &QwtAbstractLegend::staticMetaObject, qt_meta_stringdata_Legend.data,
      qt_meta_data_Legend,  qt_static_metacall, 0, 0}
};


const QMetaObject *Legend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Legend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Legend.stringdata))
        return static_cast<void*>(const_cast< Legend*>(this));
    return QwtAbstractLegend::qt_metacast(_clname);
}

int Legend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractLegend::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Legend::checked(QwtPlotItem * _t1, bool _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
