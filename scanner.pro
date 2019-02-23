QT += quick
QT += serialport
QT += charts qml
QT += sql
QT += network
#CONFIG+=qml_debug
CONFIG += c++14


SOURCES += \
    app.cpp

TARGET = NozzleBle
TEMPLATE = app

RESOURCES += \
    resource.qrc

OTHER_FILES +=

#target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/scanner
INSTALLS += target
