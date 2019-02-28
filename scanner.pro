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
    source/bluetooth/bleDevice.cpp \
    source/bluetooth/bleModelItem.cpp \
    source/bluetooth/characteristicinfo.cpp \
    source/bluetooth/deviceinfo.cpp \
    source/bluetooth/serviceinfo.cpp \
    source/bluetooth/ble.cpp \
    source/bluetooth/bleApi.cpp \
    source/bluetooth/bleModelDevice.cpp \
    source/bluetooth/bleModelService.cpp

TARGET = NozzleBle
TEMPLATE = app

RESOURCES += \
    resource.qrc

OTHER_FILES +=

#target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/scanner
INSTALLS += target

HEADERS += \
    application.h \
    source/bluetooth/bleDevice.h \
    source/bluetooth/bleModelItem.h \
    source/bluetooth/characteristicinfo.h \
    source/bluetooth/deviceinfo.h \
    source/bluetooth/serviceinfo.h \
    source/bluetooth/ble.h \
    source/bluetooth/bleApi.h \
    source/bluetooth/bleModelDevice.h \
    source/bluetooth/bleModelService.h
