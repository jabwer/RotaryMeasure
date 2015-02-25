/****************************************************************************
** Meta object code from reading C++ file 'rectf.h'
**
** Created: Tue 28. Feb 18:14:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugins/rectf/rectf.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rectf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RectF[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      12,    6, (QMetaType::QReal << 24) | 0x00195103,
      14,    6, (QMetaType::QReal << 24) | 0x00195103,
      16,    6, (QMetaType::QReal << 24) | 0x00195103,
      22,    6, (QMetaType::QReal << 24) | 0x00195103,

       0        // eod
};

static const char qt_meta_stringdata_RectF[] = {
    "RectF\0qreal\0x\0y\0width\0height\0"
};

const QMetaObject RectF::staticMetaObject = {
    { &PropertyInterface::staticMetaObject, qt_meta_stringdata_RectF,
      qt_meta_data_RectF, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RectF::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RectF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RectF::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RectF))
        return static_cast<void*>(const_cast< RectF*>(this));
    if (!strcmp(_clname, "eu.licentia.PropertyEditor.PropetyInterface/1.0"))
        return static_cast< PropertyEditor::PropertyInterface*>(const_cast< RectF*>(this));
    return PropertyInterface::qt_metacast(_clname);
}

int RectF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertyInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = x(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = y(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = width(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = height(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setX(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setY(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setWidth(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setHeight(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
