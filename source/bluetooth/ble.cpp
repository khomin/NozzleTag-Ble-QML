#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include "characteristicinfo.h"
#include "ble.h"
#include <QMenu>
#include <QVector>
#include <QPair>
#include <QTimer>
#include <QDebug>
#include <QThread>

#include "bleDevice.h"

Ble::Ble(BleModelDevice* bleModelDevice, BleModelService* bleModelService) {
    this->bleModelDevice = bleModelDevice;
    this->bleModelService = bleModelService;
    this->bleApi = new BleApi(bleModelDevice);

    connect(bleApi, &BleApi::characteristicsUpdated, this, [&]() {
        qDebug() << "characteristicsUpdated";
        auto chList = bleApi->getCharacteristics().value<QList<QObject*>>();
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
            bleModelService->appendBleDevice()
            emit bleServieCharactresticsUpdated(name, uuid, valueAsci, valueHex);
        }
    });

    connect(bleApi, &BleApi::destroyed, this, [&]() {
        qDebug() << "destroyed";
    });

    connect(bleApi, &BleApi::devicesUpdated, this, [&]() {
        qDebug() << "devicesUpdated";
    });

    connect(bleApi, &BleApi::disconnected, this, [&]() {
        qDebug() << "disconnected";
    });

    connect(bleApi, &BleApi::randomAddressChanged, this, [&]() {
        qDebug() << "randomAddressChanged";
    });

    connect(bleApi, &BleApi::servicesUpdated, this, [&]() {
        qDebug() << "servicesUpdated";
        auto serv = bleApi->getServices().value<QList<QObject*>>();
        for(auto servItem: serv) {
            auto name = ((ServiceInfo*)servItem)->getName();
            qDebug() << "serv name = " << name;
        }
        auto servList = bleApi->getServices().value<QList<QObject*>>();
        for(auto servItem: servList) {
            auto uuid = ((ServiceInfo*)servItem)->getUuid();
            bleApi->connectToService(uuid);
        }
    });

    connect(bleApi, &BleApi::stateChanged, this, [&]() {
        qDebug() << "stateChanged";
    });

    connect(bleApi, &BleApi::updateChanged, this, [&]() {
        qDebug() << "updateChanged";
    });

    connect(bleApi, &BleApi::scanFinished, this, &Ble::scanFinishedSignal);

    QTimer::singleShot(3000, Qt::CoarseTimer, this, [&]() {
        auto list = bleApi->getDevices().value<QList<BleModelItem*>>();
        for(auto i: list) {
            auto addr = i->getDevAddr();
            bleApi->scanServices(addr);
        }
    });
}

Ble::~Ble() {}

BleModelDevice* Ble::getBleModel() {
    return bleModel;
}

void Ble::startScan() {
    bleModelService->clearAll();
    bleApi->startDeviceDiscovery();
    emit scanStarted();
}

void Ble::stopScan() {

}
