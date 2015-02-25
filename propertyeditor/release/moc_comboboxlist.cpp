/****************************************************************************
** Meta object code from reading C++ file 'comboboxlist.h'
**
** Created: Tue 28. Feb 18:15:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugins/comboboxlist/comboboxlist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comboboxlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComboBoxList[] = {

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
      17,   13, 0x02195103,
      19,   13, 0x02195103,
      21,   13, 0x02195103,
      27,   13, 0x02195103,

       0        // eod
};

static const char qt_meta_stringdata_ComboBoxList[] = {
    "ComboBoxList\0int\0x\0y\0width\0height\0"
};

const QMetaObject ComboBoxList::staticMetaObject = {
    { &PropertyInterface::staticMetaObject, qt_meta_stringdata_ComboBoxList,
      qt_meta_data_ComboBoxList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComboBoxList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComboBoxList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComboBoxList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComboBoxList))
        return static_cast<void*>(const_cast< ComboBoxList*>(this));
    if (!strcmp(_clname, "eu.licentia.PropertyEditor.PropetyInterface/1.0"))
        return static_cast< PropertyEditor::PropertyInterface*>(const_cast< ComboBoxList*>(this));
    return PropertyInterface::qt_metacast(_clname);
}

int ComboBoxList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertyInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = x(); break;
        case 1: *reinterpret_cast< int*>(_v) = y(); break;
        case 2: *reinterpret_cast< int*>(_v) = width(); break;
        case 3: *reinterpret_cast< int*>(_v) = height(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setX(*reinterpret_cast< int*>(_v)); break;
        case 1: setY(*reinterpret_cast< int*>(_v)); break;
        case 2: setWidth(*reinterpret_cast< int*>(_v)); break;
        case 3: setHeight(*reinterpret_cast< int*>(_v)); break;
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
