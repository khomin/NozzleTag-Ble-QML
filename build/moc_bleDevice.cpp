/****************************************************************************
** Meta object code from reading C++ file 'bleDevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/bluetooth/bleDevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bleDevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BleDevice_t {
    QByteArrayData data[25];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BleDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BleDevice_t qt_meta_stringdata_BleDevice = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BleDevice"
QT_MOC_LITERAL(1, 10, 11), // "treeChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "bleDevicesChanged"
QT_MOC_LITERAL(4, 41, 18), // "scanFinishedSignal"
QT_MOC_LITERAL(5, 60, 8), // "getModel"
QT_MOC_LITERAL(6, 69, 9), // "addDevice"
QT_MOC_LITERAL(7, 79, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(8, 100, 16), // "on_power_clicked"
QT_MOC_LITERAL(9, 117, 7), // "clicked"
QT_MOC_LITERAL(10, 125, 23), // "on_discoverable_clicked"
QT_MOC_LITERAL(11, 149, 18), // "displayPairingMenu"
QT_MOC_LITERAL(12, 168, 3), // "pos"
QT_MOC_LITERAL(13, 172, 11), // "pairingDone"
QT_MOC_LITERAL(14, 184, 17), // "QBluetoothAddress"
QT_MOC_LITERAL(15, 202, 30), // "QBluetoothLocalDevice::Pairing"
QT_MOC_LITERAL(16, 233, 9), // "startScan"
QT_MOC_LITERAL(17, 243, 20), // "getScanningIsRunning"
QT_MOC_LITERAL(18, 264, 12), // "scanFinished"
QT_MOC_LITERAL(19, 277, 19), // "setGeneralUnlimited"
QT_MOC_LITERAL(20, 297, 9), // "unlimited"
QT_MOC_LITERAL(21, 307, 20), // "hostModeStateChanged"
QT_MOC_LITERAL(22, 328, 31), // "QBluetoothLocalDevice::HostMode"
QT_MOC_LITERAL(23, 360, 4), // "tree"
QT_MOC_LITERAL(24, 365, 17) // "QList<TestModel*>"

    },
    "BleDevice\0treeChanged\0\0bleDevicesChanged\0"
    "scanFinishedSignal\0getModel\0addDevice\0"
    "QBluetoothDeviceInfo\0on_power_clicked\0"
    "clicked\0on_discoverable_clicked\0"
    "displayPairingMenu\0pos\0pairingDone\0"
    "QBluetoothAddress\0QBluetoothLocalDevice::Pairing\0"
    "startScan\0getScanningIsRunning\0"
    "scanFinished\0setGeneralUnlimited\0"
    "unlimited\0hostModeStateChanged\0"
    "QBluetoothLocalDevice::HostMode\0tree\0"
    "QList<TestModel*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BleDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       1,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   87,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
      10,    1,   94,    2, 0x0a /* Public */,
      11,    1,   97,    2, 0x0a /* Public */,
      13,    2,  100,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    1,  108,    2, 0x08 /* Private */,
      21,    1,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15,    2,    2,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, 0x80000000 | 22,    2,

 // properties: name, type, flags
      23, 0x80000000 | 24, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void BleDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BleDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->treeChanged(); break;
        case 1: _t->bleDevicesChanged(); break;
        case 2: _t->scanFinishedSignal(); break;
        case 3: _t->getModel(); break;
        case 4: _t->addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 5: _t->on_power_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_discoverable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->displayPairingMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->pairingDone((*reinterpret_cast< const QBluetoothAddress(*)>(_a[1])),(*reinterpret_cast< QBluetoothLocalDevice::Pairing(*)>(_a[2]))); break;
        case 9: _t->startScan(); break;
        case 10: { bool _r = _t->getScanningIsRunning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->scanFinished(); break;
        case 12: _t->setGeneralUnlimited((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->hostModeStateChanged((*reinterpret_cast< QBluetoothLocalDevice::HostMode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothAddress >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothLocalDevice::Pairing >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothLocalDevice::HostMode >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BleDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BleDevice::treeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BleDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BleDevice::bleDevicesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BleDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BleDevice::scanFinishedSignal)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<TestModel*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BleDevice *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<TestModel*>*>(_v) = _t->treeAsQObjects(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BleDevice::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BleDevice.data,
    qt_meta_data_BleDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BleDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BleDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BleDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BleDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BleDevice::treeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BleDevice::bleDevicesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BleDevice::scanFinishedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
