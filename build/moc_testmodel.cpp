/****************************************************************************
** Meta object code from reading C++ file 'testmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestModel_t {
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestModel_t qt_meta_stringdata_TestModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TestModel"
QT_MOC_LITERAL(1, 10, 14), // "devNameChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "devActiveChanged"
QT_MOC_LITERAL(4, 43, 14), // "devAddrChanged"
QT_MOC_LITERAL(5, 58, 10), // "getDevName"
QT_MOC_LITERAL(6, 69, 10), // "setDevName"
QT_MOC_LITERAL(7, 80, 7), // "devName"
QT_MOC_LITERAL(8, 88, 10), // "getDevAddr"
QT_MOC_LITERAL(9, 99, 10), // "setDevAddr"
QT_MOC_LITERAL(10, 110, 7), // "devAddr"
QT_MOC_LITERAL(11, 118, 11), // "getIsActive"
QT_MOC_LITERAL(12, 130, 9), // "setActive"
QT_MOC_LITERAL(13, 140, 6), // "active"
QT_MOC_LITERAL(14, 147, 10), // "devAddress"
QT_MOC_LITERAL(15, 158, 8) // "isActive"

    },
    "TestModel\0devNameChanged\0\0devActiveChanged\0"
    "devAddrChanged\0getDevName\0setDevName\0"
    "devName\0getDevAddr\0setDevAddr\0devAddr\0"
    "getIsActive\0setActive\0active\0devAddress\0"
    "isActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   13,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495003,
      15, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       2,
       1,

       0        // eod
};

void TestModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->devNameChanged(); break;
        case 1: _t->devActiveChanged(); break;
        case 2: _t->devAddrChanged(); break;
        case 3: { QString _r = _t->getDevName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setDevName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->getDevAddr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setDevAddr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->getIsActive();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestModel::devNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TestModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestModel::devActiveChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TestModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestModel::devAddrChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TestModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getDevName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getDevAddr(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getIsActive(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TestModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDevName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDevAddr(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TestModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TestModel.data,
    qt_meta_data_TestModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TestModel::devNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TestModel::devActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TestModel::devAddrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
