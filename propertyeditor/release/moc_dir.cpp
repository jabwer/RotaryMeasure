/****************************************************************************
** Meta object code from reading C++ file 'dir.h'
**
** Created: Tue 28. Feb 18:14:47 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugins/dir/dir.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dir[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    5,    4,    4, 0x0a,
      27,   25,    4,    4, 0x0a,
      46,   25,    4,    4, 0x0a,

 // properties: name, type, flags
      75,   67, 0x0a095103,
      89,   82, 0x02095103,

       0        // eod
};

static const char qt_meta_stringdata_Dir[] = {
    "Dir\0\0c\0setValue(QString)\0s\0"
    "setFilter(QString)\0setSelectDir(qint32)\0"
    "QString\0filter\0qint32\0selectDir\0"
};

const QMetaObject Dir::staticMetaObject = {
    { &PropertyInterface::staticMetaObject, qt_meta_stringdata_Dir,
      qt_meta_data_Dir, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dir::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dir::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dir))
        return static_cast<void*>(const_cast< Dir*>(this));
    if (!strcmp(_clname, "eu.licentia.PropertyEditor.PropetyInterface/1.0"))
        return static_cast< PropertyEditor::PropertyInterface*>(const_cast< Dir*>(this));
    return PropertyInterface::qt_metacast(_clname);
}

int Dir::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertyInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: setFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setSelectDir((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = filter(); break;
        case 1: *reinterpret_cast< qint32*>(_v) = selectDir(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFilter(*reinterpret_cast< QString*>(_v)); break;
        case 1: setSelectDir(*reinterpret_cast< qint32*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
