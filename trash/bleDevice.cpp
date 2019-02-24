/****************************************************************************
**
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

#include "bleDevice.h"
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <QMenu>
#include <QDebug>
#include <QVector>
#include <QPair>

#include <QTimer>

BleDevice::BleDevice(const QString devName, QString devAddr) {
    this->devAddr = devAddr;
    this->devName = devName;
//    scanningIsRunning = false;
//    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
//    localDevice = new QBluetoothLocalDevice();

//    //    connect(ui->inquiryType, SIGNAL(toggled(bool)), this, SLOT(setGeneralUnlimited(bool)));
//    //    connect(ui->scan, SIGNAL(clicked()), this, SLOT(startScan()));

//    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
//            this, SLOT(addDevice(QBluetoothDeviceInfo)));
//    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));

//    //    connect(ui->list, SIGNAL(itemActivated(QListWidgetItem*)),
//    //            this, SLOT(itemActivated(QListWidgetItem*)));

//    connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
//            this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));

//    hostModeStateChanged(localDevice->hostMode());
//    // add context menu for devices to be able to pair device
//    //    ui->list->setContextMenuPolicy(Qt::CustomContextMenu);
//    //    connect(ui->list, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(displayPairingMenu(QPoint)));
//    //    connect(localDevice, SIGNAL(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing))
//    //        , this, SLOT(pairingDone(QBluetoothAddress,QBluetoothLocalDevice::Pairing)));

////    bleDeviceList.append(new TestModel("Item 1", "ttt"));
////    bleDeviceList.append(new TestModel("Item 2", "ttt"));
////    bleDeviceList.append(new TestModel("Item 3", "ttt"));
////    bleDeviceList.append(new TestModel("Item 4", "ttt"));
////    auto t = dynamic_cast<TestModel*>(bleDeviceList.first());
////    t->setActive(true);

//    QTimer::singleShot(1000, this, [&] {
//        bleDeviceList.append(new TestModel("Item 1", "ttt"));
//        bleDeviceList.append(new TestModel("Item 2", "ttt"));
//        bleDeviceList.append(new TestModel("Item 3", "ttt"));
//        bleDeviceList.append(new TestModel("Item 4", "ttt"));
//        auto t = dynamic_cast<TestModel*>(bleDeviceList.first());
////        bleDeviceList.
//        t->setActive(true);
//        emit treeChanged();
//    });
}

BleDevice::~BleDevice() {
//    delete discoveryAgent;
}

//const QList<TestModel*> BleDevice::treeAsQObjects() const {
//    return bleDeviceList;
//}

//void BleDevice::addDevice(const QBluetoothDeviceInfo &info) {
////        bleDeviceList.append(new TestModel("Item 1", "ttt"));
////        bleDeviceList.append(new TestModel("Item 2", "ttt"));
////        bleDeviceList.append(new TestModel("Item 3", "ttt"));
////        bleDeviceList.append(new TestModel("Item 4", "ttt"));
////        auto t = dynamic_cast<TestModel*>(bleDeviceList.first());
////        t->setActive(true);
////        emit treeChanged();

//    //    devList.append(std::move(new QPair<QString,QString>(info.address().toString(), info.name())));

////    bleDeviceList.append(new TestModel("Item 1", "ttt"));
////    bleDeviceList.append(new TestModel("Item 2", "ttt"));
////    bleDeviceList.append(new TestModel("Item 3", "ttt"));
////    bleDeviceList.append(new TestModel("Item 4", "ttt"));

//    //    QString label = QString("%1 %2").arg(info.address().toString()).arg();
//    //    QList<QListItem *> items = ui->list->findItems(label, Qt::MatchExactly);
//    //    if (items.empty()) {
//    //        QListWidgetItem *item = new QListWidgetItem(label);
//    //        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
//    //        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
//    //            item->setTextColor(QColor(Qt::green));
//    //        else
//    //            item->setTextColor(QColor(Qt::black));
//    //        ui->list->addItem(item);
//    //    }
//    //    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
//    //    QList<QListWidgetItem *> items = ui->list->findItems(label, Qt::MatchExactly);
//    //    if (items.empty()) {
//    //        QListWidgetItem *item = new QListWidgetItem(label);
//    //        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
//    //        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
//    //            item->setTextColor(QColor(Qt::green));
//    //        else
//    //            item->setTextColor(QColor(Qt::black));

//    //        ui->list->addItem(item);
//    //    }
//}

//void BleDevice::startScan() {
//    discoveryAgent->start();
//    scanningIsRunning = true;
//}

//bool BleDevice::getScanningIsRunning() {
//    return scanningIsRunning ;
//}

//void BleDevice::scanFinished() {
//    //    ui->scan->setEnabled(true);
//    //    ui->inquiryType->setEnabled(true);
//    scanningIsRunning = false;
//    emit scanFinishedSignal();
//}

//void BleDevice::setGeneralUnlimited(bool unlimited) {
//    if (unlimited)
//        discoveryAgent->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);
//    else
//        discoveryAgent->setInquiryType(QBluetoothDeviceDiscoveryAgent::LimitedInquiry);
//}

////void BleDevice::itemActivated(QListWidgetItem *item) {
////    QString text = item->text();

////    int index = text.indexOf(' ');

////    if (index == -1)
////        return;

////    QBluetoothAddress address(text.left(index));
////    QString name(text.mid(index + 1));

////    ServiceDiscoveryDialog d(name, address);
////    d.exec();
////}

//void BleDevice::on_discoverable_clicked(bool clicked) {
//    if (clicked)
//        localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
//    else
//        localDevice->setHostMode(QBluetoothLocalDevice::HostConnectable);
//}

//void BleDevice::on_power_clicked(bool clicked) {
//    if (clicked)
//        localDevice->powerOn();
//    else
//        localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
//}

//void BleDevice::hostModeStateChanged(QBluetoothLocalDevice::HostMode mode) {
//    //    if (mode != QBluetoothLocalDevice::HostPoweredOff)
//    //        ui->power->setChecked(true);
//    //    else
//    //       ui->power->setChecked( false);

//    //    if (mode == QBluetoothLocalDevice::HostDiscoverable)
//    //        ui->discoverable->setChecked(true);
//    //    else
//    //        ui->discoverable->setChecked(false);

//    //    bool on = !(mode == QBluetoothLocalDevice::HostPoweredOff);


//    //    ui->scan->setEnabled(on);
//    //    ui->discoverable->setEnabled(on);
//}

//void BleDevice::displayPairingMenu(const QPoint &pos) {
//    //    if (ui->list->count() == 0)
//    //        return;
//    //    QMenu menu(this);
//    //    QAction *pairAction = menu.addAction("Pair");
//    //    QAction *removePairAction = menu.addAction("Remove Pairing");
//    //    QAction *chosenAction = menu.exec(ui->list->viewport()->mapToGlobal(pos));
//    //    QListWidgetItem *currentItem = ui->list->currentItem();

//    //    QString text = currentItem->text();
//    //    int index = text.indexOf(' ');
//    //    if (index == -1)
//    //        return;

//    //    QBluetoothAddress address (text.left(index));
//    //    if (chosenAction == pairAction) {
//    //        localDevice->requestPairing(address, QBluetoothLocalDevice::Paired);
//    //    } else if (chosenAction == removePairAction) {
//    //        localDevice->requestPairing(address, QBluetoothLocalDevice::Unpaired);
//    //    }
//}

//void BleDevice::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing) {
//    //    QList<QListWidgetItem *> items = ui->list->findItems(address.toString(), Qt::MatchContains);

//    //    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired ) {
//    //        for (int var = 0; var < items.count(); ++var) {
//    //            QListWidgetItem *item = items.at(var);
//    //            item->setTextColor(QColor(Qt::green));
//    //        }
//    //    } else {
//    //        for (int var = 0; var < items.count(); ++var) {
//    //            QListWidgetItem *item = items.at(var);
//    //            item->setTextColor(QColor(Qt::red));
//    //        }
//    //    }
//}

//QList<TestModel*>& BleDevice::getModel() {
//    return bleDeviceList;
//}
