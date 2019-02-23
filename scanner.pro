QT += quick
QT += serialport
QT += charts qml
QT += sql
QT += network
CONFIG+=qml_debug
CONFIG += c++14


SOURCES += qmlscanner.cpp

TARGET = qml_scanner
TEMPLATE = app

RESOURCES += \
    scanner.qrc

OTHER_FILES += \
    scanner.qml \
    default.png

#DEFINES += QMLJSDEBUGGER

target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/scanner
INSTALLS += target
