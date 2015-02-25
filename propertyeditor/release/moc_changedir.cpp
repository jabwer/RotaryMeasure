/****************************************************************************
** Meta object code from reading C++ file 'changedir.h'
**
** Created: Tue 28. Feb 18:14:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugins/dir/changedir.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changedir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangeDir[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x0a,
      47,   45,   10,   10, 0x0a,
      66,   45,   10,   10, 0x0a,

 // properties: name, type, flags
      95,   87, 0x0a095103,
     109,  102, 0x02095103,

       0        // eod
};

static const char qt_meta_stringdata_ChangeDir[] = {
    "ChangeDir\0\0dir\0dirChanged(QString)\0"
    "onClick()\0s\0setFilter(QString)\0"
    "setSelectDir(qint32)\0QString\0filter\0"
    "qint32\0selectDir\0"
};

const QMetaObject ChangeDir::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChangeDir,
      qt_meta_data_ChangeDir, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangeDir::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangeDir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangeDir::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeDir))
        return static_cast<void*>(const_cast< ChangeDir*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChangeDir::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dirChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: onClick(); break;
        case 2: setFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: setSelectDir((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
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

// SIGNAL 0
void ChangeDir::dirChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
