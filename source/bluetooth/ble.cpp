#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include "ble.h"
#include <QMenu>
#include <QDebug>
#include <QVector>
#include <QPair>
#include <QTimer>

BleDevice::BleDevice() {
    scanningIsRunning = false;
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    localDevice = new QBluetoothLocalDevice();

    //    connect(ui->inquiryType, SIGNAL(toggled(bool)), this, SLOT(setGeneralUnlimited(bool)));
    //    connect(ui->scan, SIGNAL(clicked()), this, SLOT(startScan()));

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this,
        [&] (const QBluetoothDeviceInfo & info) {
        bleModel.addBle(new BleModelItem(info.name(), info.address().toString()));
        }
    );
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this,  [&]() {
        scanningIsRunning = false;
        emit scanFinishedSignal();
    });
    //    connect(ui->list, SIGNAL(itemActivated(QListWidgetItem*)),
    //            this, SLOT(itemActivated(QListWidgetItem*)));
//    connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
//            this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));
//    hostModeStateChanged(localDevice->hostMode());
    // add context menu for devices to be able to pair device
    //    ui->list->setContextMenuPolicy(Qt::CustomContextMenu);
    //    connect(ui->list, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(displayPairingMenu(QPoint)));
    //    connect(localDevice, SIGNAL(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing))
    //        , this, SLOT(pairingDone(QBluetoothAddress,QBluetoothLocalDevice::Pairing)));
    startScan();
}

BleDevice::~BleDevice() {
    delete discoveryAgent;
}

BleModel* BleDevice::getBleModel() {
    return &bleModel;
}

void BleDevice::startScan() {
    discoveryAgent->start();
    scanningIsRunning = true;
}

bool BleDevice::getScanningIsRunning() {
    return scanningIsRunning ;
}

void BleDevice::on_discoverable_clicked(bool clicked) {
    if (clicked)
        localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    else
        localDevice->setHostMode(QBluetoothLocalDevice::HostConnectable);
}

void BleDevice::on_power_clicked(bool clicked) {
    if (clicked)
        localDevice->powerOn();
    else
        localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}

void BleDevice::displayPairingMenu(const QPoint &pos) {
    //    if (ui->list->count() == 0)
    //        return;
    //    QMenu menu(this);
    //    QAction *pairAction = menu.addAction("Pair");
    //    QAction *removePairAction = menu.addAction("Remove Pairing");
    //    QAction *chosenAction = menu.exec(ui->list->viewport()->mapToGlobal(pos));
    //    QListWidgetItem *currentItem = ui->list->currentItem();

    //    QString text = currentItem->text();
    //    int index = text.indexOf(' ');
    //    if (index == -1)
    //        return;

    //    QBluetoothAddress address (text.left(index));
    //    if (chosenAction == pairAction) {
    //        localDevice->requestPairing(address, QBluetoothLocalDevice::Paired);
    //    } else if (chosenAction == removePairAction) {
    //        localDevice->requestPairing(address, QBluetoothLocalDevice::Unpaired);
    //    }
}

void BleDevice::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing) {
    //    QList<QListWidgetItem *> items = ui->list->findItems(address.toString(), Qt::MatchContains);

    //    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired ) {
    //        for (int var = 0; var < items.count(); ++var) {
    //            QListWidgetItem *item = items.at(var);
    //            item->setTextColor(QColor(Qt::green));
    //        }
    //    } else {
    //        for (int var = 0; var < items.count(); ++var) {
    //            QListWidgetItem *item = items.at(var);
    //            item->setTextColor(QColor(Qt::red));
    //        }
    //    }
}
