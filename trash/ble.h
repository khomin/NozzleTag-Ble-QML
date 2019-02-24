#ifndef BLE_H
#define BLE_H

#include <QObject>
#include "bluetoothModel.h"
#include "bleDevice.h"

class ble : public QObject
{
    Q_OBJECT
public:
    explicit ble(QObject *parent = nullptr);

    BluetoothModel model;

signals:

public slots:
};

#endif // BLE_H
