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
    source/bluetooth/BleApi.cpp \
    source/bluetooth/bleDevice.cpp \
    source/bluetooth/bleModel.cpp \
    source/bluetooth/bleModelItem.cpp \
    source/bluetooth/characteristicinfo.cpp \
    source/bluetooth/deviceinfo.cpp \
    source/bluetooth/devices.cpp \
    source/bluetooth/serviceinfo.cpp

TARGET = NozzleBle
TEMPLATE = app

RESOURCES += \
    resource.qrc

OTHER_FILES +=

#target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/scanner
INSTALLS += target

HEADERS += \
    application.h \
    source/bluetooth/BleApi.h \
    source/bluetooth/bleDevice.h \
    source/bluetooth/bleModel.h \
    source/bluetooth/bleModelItem.h \
    source/bluetooth/characteristicinfo.h \
    source/bluetooth/deviceinfo.h \
    source/bluetooth/devices.h \
    source/bluetooth/serviceinfo.h
