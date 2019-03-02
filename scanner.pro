QT += quick
QT += serialport
QT += charts qml
QT += sql
QT += network
QT += bluetooth

CONFIG+=qml_debug
CONFIG += c++14


SOURCES += \
    app.cpp \
    application.cpp \
    source/bluetooth/ble.cpp \
    source/bluetooth/api/bleApi.cpp \
    source/bluetooth/device/bleDevice.cpp \
    source/bluetooth/device/bleModelDevice.cpp \
    source/bluetooth/device/characteristicinfo.cpp \
    source/bluetooth/device/deviceinfo.cpp \
    source/bluetooth/device/bleModelDeviceItem.cpp \
    source/bluetooth/service/bleModelService.cpp \
    source/bluetooth/service/serviceinfo.cpp \
    source/bluetooth/service/bleModelServiceItem.cpp

TARGET = NozzleBle
TEMPLATE = app

RESOURCES += \
    resource.qrc

OTHER_FILES +=

#target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/scanner
INSTALLS += target

HEADERS += \
    application.h \
    source/bluetooth/ble.h \
    source/bluetooth/api/bleApi.h \
    source/bluetooth/device/bleDevice.h \
    source/bluetooth/device/bleModelDevice.h \
    source/bluetooth/device/characteristicinfo.h \
    source/bluetooth/device/deviceinfo.h \
    source/bluetooth/service/bleModelService.h \
    source/bluetooth/service/serviceinfo.h \
    source/bluetooth/device/bleModelDeviceItem.h \
    source/bluetooth/service/bleModelServicetem.h
