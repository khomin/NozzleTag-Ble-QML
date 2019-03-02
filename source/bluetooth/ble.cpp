#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <QMenu>
#include <QVector>
#include <QPair>
#include <QTimer>
#include <QDebug>
#include "source/bluetooth/device/characteristicinfo.h"
#include "source/bluetooth/device/bleDevice.h"
#include "source/bluetooth/ble.h"

Ble::Ble(BleModelDevice* bleModelDevice, BleModelService* bleModelService) {
    this->m_ble_model_device = bleModelDevice;
    this->m_ble_model_service = bleModelService;
    this->bleApi = std::make_shared<BleApi>(bleModelDevice);

    connect(bleApi.get(), &BleApi::characteristicsChanged, this, [&]() {
        qDebug() << "characteristicsUpdated";
        auto chList = bleApi->getCharacteristics();
        for(auto chListItem: chList) {
            QString name = chListItem->getCharacteristic().name();
            QString uuid = chListItem->getCharacteristic().uuid().toString();
            QString valueHex;
            QString valueAsci;
            auto tvalue = chListItem->getValue();
            for(auto i: tvalue) {
                valueHex += "0x" + QString::number(i&0xFF, 16) + " ";
            }
            valueAsci = QString::fromUtf8(tvalue.data(), tvalue.length());
            qDebug() << "name#: " << name;
            qDebug() << "uuid#: " << uuid;
            qDebug() << "valueAsci#: " << valueHex;

            m_ble_model_service->appendBleService(new BleModelServiceItem(name, uuid, valueHex, valueAsci));

            if(uuid == "{f0001185-0451-4000-b000-000000000000}") {
                auto dev = m_ble_model_device->getBleDevices();
                for(auto d: dev) {
                    if(d->getDevName() == "Locus NozzleTag") {
                        d->setAccelX(valueHex);
                        m_ble_model_device->appendBleDevice(d);
                    }
                }
            }
            emit bleServieCharactresticsUpdated(name, uuid, valueAsci, valueHex);
        }
    });

    connect(bleApi.get(), &BleApi::destroyed, this, [&]() {
        qDebug() << "destroyed";
    });

    connect(bleApi.get(), &BleApi::devicesUpdated, this, [&]() {
        qDebug() << "devicesUpdated";
    });

    connect(bleApi.get(), &BleApi::disconnected, this, [&]() {
        qDebug() << "disconnected";
    });

    connect(bleApi.get(), &BleApi::randomAddressChanged, this, [&]() {
        qDebug() << "randomAddressChanged";
    });

    connect(bleApi.get(), &BleApi::servicesUpdated, this, [&]() {
        qDebug() << "servicesUpdated";
        auto serv = bleApi->getServices();
        for(auto servItem: serv) {
            auto name = servItem->getName();
            qDebug() << "serv name = " << name;
        }
        auto servList = bleApi->getServices();
        for(auto servItem: servList) {
            auto uuid = servItem->getUuid();
            bleApi->connectToService(uuid);
        }
    });

    connect(bleApi.get(), &BleApi::stateChanged, this, [&]() {
        qDebug() << "stateChanged";
    });

    connect(bleApi.get(), &BleApi::updateChanged, this, [&]() {
        qDebug() << "updateChanged";
    });

    connect(bleApi.get(), &BleApi::scanFinished, this, &Ble::scanFinishedSignal);

//    QTimer::singleShot(3000, Qt::CoarseTimer, this, [&]() {
//        auto list = bleApi->getDevices().value<QList<BleModelDeviceItem*>>();
//        for(auto i: list) {
//            auto addr = i->getDevAddr();
//            bleApi->scanServices(addr.toString());
//        }
//    });
}

Ble::~Ble() {}

BleModelDevice* Ble::getBleModelDevice() {
    return m_ble_model_device;
}

void Ble::startScan() {
    m_ble_model_service->clearAll();
    m_ble_model_device->clearAll();
    bleApi->startDeviceDiscovery();
    emit scanStarted();
}
