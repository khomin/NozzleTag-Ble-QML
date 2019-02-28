#ifndef BleModelItem_H
#define BleModelItem_H

#include <QObject>
#include "deviceinfo.h"

class BleModelItem : public QObject
{
    Q_OBJECT
public:
    BleModelItem(const QString devName,
                 const QString devAddr,
                 const int rssi,
                 const QBluetoothDeviceInfo & info,
                 DeviceInfo * customInfo = nullptr);
    QString getDevName() const;
    QString getDevAddr() const;
    int getRssi() const;
    DeviceInfo* getDevCustomInfo() const;
    QBluetoothDeviceInfo & getDevInfo();

private:
    DeviceInfo* m_custom_info;
    QString m_devName;
    QString m_devAddr;
    int m_rssi;
    QList<QObject*> m_services;
    QBluetoothDeviceInfo m_dev_info;
};

#endif // BleModelItem_H
