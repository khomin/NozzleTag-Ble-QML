/***************************************************************************
**
** Copyright (C) 2013 BlackBerry Limited. All rights reserved.
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "bleApi.h"

#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothservicediscoveryagent.h>
#include "source/bluetooth/device/bleModelDevice.h"
#include <QDebug>
#include <QList>
#include <QMetaEnum>
#include <QTimer>

BleApi::BleApi(BleModelDevice* bleModel) {
    this->bleModel = std::make_shared<BleModelDevice>(bleModel);

    discoveryAgent = std::make_shared<QBluetoothDeviceDiscoveryAgent>();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent.get(), &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BleApi::addDevice);
    connect(discoveryAgent.get(), QOverload<QBluetoothDeviceDiscoveryAgent::Error>::of(&QBluetoothDeviceDiscoveryAgent::error),
            this, &BleApi::deviceScanError);
    connect(discoveryAgent.get(), &QBluetoothDeviceDiscoveryAgent::finished, this, &BleApi::deviceScanFinished);
}

BleApi::~BleApi() {}

void BleApi::startDeviceDiscovery() {
    bleModel->clearAll();
    emit devicesUpdated();
    qDebug() << "Scan reset";
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

    if (discoveryAgent->isActive()) {
        m_deviceScanState = true;
        emit stateChanged();
    }
}

void BleApi::addDevice(const QBluetoothDeviceInfo &info) {
    if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
        std::shared_ptr<BleModelDeviceItem> pdev = std::make_shared<BleModelDeviceItem>(info.name(),
                                     info.address().toString(),
                                     info.rssi(),
                                     info,
                                     new DeviceInfo(info));
        qDebug() << "Last device added: " + pdev->getDevName().toString();
        bleModel->appendBleDevice(std::move(pdev));
    }
}

void BleApi::deviceScanFinished() {
    emit devicesUpdated();
    m_deviceScanState = false;
    emit stateChanged();
    if (bleModel->getCountDevices() == 0)
        qDebug() << "No Low Energy devices found...";
    else
        qDebug() << "Done! Scan Again!";
    emit scanFinished();
}

QList<std::shared_ptr<BleModelDeviceItem>>& BleApi::getDevices() {
    return bleModel->getBleDevices();
}

QList<std::shared_ptr<ServiceInfo>>& BleApi::getServices() {
    return m_services;
}

QList<std::shared_ptr<CharacteristicInfo>>& BleApi::getCharacteristics() {
    return m_characteristics;
}

void BleApi::scanServices(const QString &address) {
    // We need the current device for service discovery.
    auto devices = bleModel->getBleDevices();

    for (auto d: devices) {
        if (d->getDevAddr() == address ) {
            currentDevice->setDevice(d->getDevInfo());
        }
    }

    if (!currentDevice->getDevice().isValid()) {
        qWarning() << "Not a valid device";
        return;
    }

    m_characteristics.clear();
    emit characteristicsChanged();
    m_services.clear();
    emit servicesUpdated();

    qDebug() << "Back\n(Connecting to device...)";

    if (controller.get() && m_previousAddress != currentDevice->getAddress()) {
        controller->disconnectFromDevice();
        controller.reset();
    }

    if (!controller) {
        // Connecting signals and slots for connecting to LE services.
        controller = std::make_shared<QLowEnergyController>(currentDevice->getDevice());
        controller->disconnectFromDevice();
        connect(controller.get(), &QLowEnergyController::connected,
                this, &BleApi::deviceConnected);
        connect(controller.get(), QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),
                this, &BleApi::errorReceived);
        connect(controller.get(), &QLowEnergyController::disconnected,
                this, &BleApi::deviceDisconnected);
        connect(controller.get(), &QLowEnergyController::serviceDiscovered,
                this, &BleApi::addLowEnergyService);
        connect(controller.get(), &QLowEnergyController::discoveryFinished,
                this, &BleApi::serviceScanDone);
    }

    if (isRandomAddress())
        controller->setRemoteAddressType(QLowEnergyController::RandomAddress);
    else
        controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    controller->connectToDevice();

    m_previousAddress = currentDevice->getAddress();
}

void BleApi::addLowEnergyService(const QBluetoothUuid &serviceUuid) {
    QLowEnergyService *service = controller->createServiceObject(serviceUuid);
    connect(service, &QLowEnergyService::stateChanged, this, &BleApi::characteristicsChanged);
    connect(service, &QLowEnergyService::characteristicChanged, this, &BleApi::characteristicsChanged);
    connect(service, &QLowEnergyService::descriptorWritten, this, &BleApi::characteristicsChanged);
    service->discoverDetails();
    if (!service) {
        qWarning() << "Cannot create service for uuid";
        return;
    }
    std::shared_ptr<ServiceInfo>serv = std::make_shared<ServiceInfo>(service);

    connect(service, &QLowEnergyService::characteristicChanged, this, &BleApi::characteristicsChanged);
    m_services.append(std::move(serv));
    emit servicesUpdated();
}

void BleApi::serviceScanDone() {
    qDebug() << "Back\n(Service scan done!)";
    // force UI in case we didn't find anything
    if (m_services.isEmpty()) {
        emit servicesUpdated();
    }
}

void BleApi::connectToService(const QString &uuid) {
    QLowEnergyService *service = nullptr;
    for (auto s: m_services) {
        if (!s.get())
            continue;
        if (s->getUuid() == uuid) {
            service = s->service();
            break;
        }
    }

    if (!service)
        return;
    m_characteristics.clear();

    if (service->state() == QLowEnergyService::DiscoveryRequired) {
        connect(service, &QLowEnergyService::stateChanged,
                this, &BleApi::serviceDetailsDiscovered);
        service->discoverDetails();
        qDebug() << "Back\n(Discovering details...)";
        return;
    }

    //discovery already done
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        std::shared_ptr<CharacteristicInfo> cInfo = std::make_shared<CharacteristicInfo>(ch);
        m_characteristics.append(std::move(cInfo));
    }
}

void BleApi::deviceConnected() {
    qDebug() << "Back\n(Discovering services...)";
    connected = true;
    controller->discoverServices();
}

void BleApi::errorReceived(QLowEnergyController::Error /*error*/) {
    qWarning() << "Error: " << controller->errorString();
    qDebug() << QString("Back\n(%1)").arg(controller->errorString());
}

void BleApi::disconnectFromDevice() {
    // UI always expects disconnect() signal when calling this signal
    // TODO what is really needed is to extend state() to a multi value
    // and thus allowing UI to keep track of controller progress in addition to
    // device scan progress

    if (controller->state() != QLowEnergyController::UnconnectedState)
        controller->disconnectFromDevice();
    else
        deviceDisconnected();
}

void BleApi::deviceDisconnected() {
    qDebug() << "Disconnect from device";
    emit disconnected();
}

void BleApi::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState) {
    if (newState != QLowEnergyService::ServiceDiscovered) {
        // do not hang in "Scanning for characteristics" mode forever
        // in case the service discovery failed
        // We have to queue the signal up to give UI time to even enter
        // the above mode
        if (newState != QLowEnergyService::DiscoveringServices) {
            QMetaObject::invokeMethod(this, "characteristicsUpdated",
                                      Qt::QueuedConnection);
        }
        return;
    }

    auto service = qobject_cast<QLowEnergyService *>(sender());
    if (!service)
        return;

    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        std::shared_ptr<CharacteristicInfo> cInfo = std::make_shared<CharacteristicInfo>(ch);
        m_characteristics.append(std::move(cInfo));
    }
    emit characteristicsChanged();
}

void BleApi::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error) {
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
        qDebug() << "The Bluetooth adaptor is powered off, power it on before doing discovery.";
    else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
        qDebug() << "Writing or reading from the device resulted in an error.";
    else {
        static QMetaEnum qme = discoveryAgent->metaObject()->enumerator(
                    discoveryAgent->metaObject()->indexOfEnumerator("Error"));
        qDebug() << "Error: " + QLatin1String(qme.valueToKey(error));
    }

    m_deviceScanState = false;
    emit devicesUpdated();
    emit stateChanged();
    emit scanFinished();
}

bool BleApi::state() {
    return m_deviceScanState;
}

bool BleApi::hasControllerError() const {
    return (controller && controller->error() != QLowEnergyController::NoError);
}

bool BleApi::isRandomAddress() const {
    return randomAddress;
}

void BleApi::setRandomAddress(bool newValue) {
    randomAddress = newValue;
    emit randomAddressChanged();
}
