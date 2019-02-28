#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include "characteristicinfo.h"
#include "BleApi.h"
#include <QMenu>
#include <QVector>
#include <QPair>
#include <QTimer>
#include <QDebug>
#include <QThread>

BleApi::BleApi() {
    device = new Devices(&bleModel);

    connect(device, &Devices::characteristicsUpdated, this, [&]() {
        qDebug() << "characteristicsUpdated";
        auto chList = device->getCharacteristics().value<QList<QObject*>>();
        for(auto chListItem: chList) {
            QString name = ((CharacteristicInfo*)chListItem)->getCharacteristic().name();
            QString uuid = ((CharacteristicInfo*)chListItem)->getCharacteristic().uuid().toString();
            QString valueHex;
            QString valueAsci;
            auto tvalue = ((CharacteristicInfo*)chListItem)->getValue();
            for(auto i: tvalue) {
                valueHex += "0x" + QString::number(i&0xFF, 16) + " ";
            }
            valueAsci = QString::fromUtf8(tvalue.data(), tvalue.length());
            qDebug() << "name#: " << name;
            qDebug() << "uuid#: " << uuid;
            qDebug() << "valueAsci#: " << valueHex;
            emit bleServieCharactresticsUpdated(name, uuid, valueAsci, valueHex);
        }
    });
    connect(device, &Devices::destroyed, this, [&]() {
        qDebug() << "destroyed";
    });
    connect(device, &Devices::devicesUpdated, this, [&]() {
        qDebug() << "devicesUpdated";
    });
    connect(device, &Devices::disconnected, this, [&]() {
        qDebug() << "disconnected";
    });
    connect(device, &Devices::randomAddressChanged, this, [&]() {
        qDebug() << "randomAddressChanged";
    });
    connect(device, &Devices::servicesUpdated, this, [&]() {
        qDebug() << "servicesUpdated";
        auto serv = device->getServices().value<QList<QObject*>>();
        for(auto servItem: serv) {
            auto name = ((ServiceInfo*)servItem)->getName();
            qDebug() << "serv name = " << name;
        }
        auto servList = device->getServices().value<QList<QObject*>>();
        for(auto servItem: servList) {
            auto uuid = ((ServiceInfo*)servItem)->getUuid();
            device->connectToService(uuid);
        }
    });
    connect(device, &Devices::stateChanged, this, [&]() {
        qDebug() << "stateChanged";
    });
    connect(device, &Devices::updateChanged, this, [&]() {
        qDebug() << "updateChanged";
    });

    connect(device, &Devices::scanFinished, this, &BleApi::scanFinishedSignal);

    QTimer::singleShot(1000, Qt::CoarseTimer, this, [&]() {
        auto list = device->getDevices().value<QList<QObject*>>();
        for(auto item: list) {
            auto addr = ((DeviceInfo*)item)->getAddress();
            device->scanServices(addr);
        }
    });
}

BleApi::~BleApi() {}

BleModel* BleApi::getBleModel() {
    return &bleModel;
}

void BleApi::startScan() {
    device->startDeviceDiscovery();
    emit scanStarted();
}

void BleApi::deviceConnected() {
    qDebug() << "deviceConnected";
    //    setUpdate("Back\n(Discovering services...)");
    //    connected = true;
    //! [les-service-2]
    //    controller->discoverServices();
    //! [les-service-2]
}
