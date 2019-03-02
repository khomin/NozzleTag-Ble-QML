#ifndef BleModelItem_H
#define BleModelItem_H

#include <QObject>
#include "deviceinfo.h"

class BleModelDeviceItem : public QObject
{
    Q_OBJECT
public:
    BleModelDeviceItem(const QString devName,
                 const QString devAddr,
                 const int rssi,
                 const QBluetoothDeviceInfo & info,
                 DeviceInfo * customInfo = nullptr);
   ~BleModelDeviceItem();

    void setDevName(const QVariant val);
    void setDevAddr(const QVariant val);
    void setRssi(const QVariant val);
    void setAccelX(const QVariant val);
    void setAccelY(const QVariant val);
    void setAccelZ(const QVariant val);
    QVariant getDevName() const;
    QVariant getDevAddr() const;
    QVariant getRssi() const;
    QVariant getAccelX() const;
    QVariant getAccelY() const;
    QVariant getAccelZ() const;
    DeviceInfo* getDevCustomInfo() const;
    QBluetoothDeviceInfo & getDevInfo();

private:
    DeviceInfo* m_custom_info;
    QVariant m_devName;
    QVariant m_devAddr;
    QVariant m_rssi;
    QVariant m_accelX;
    QVariant m_accelY;
    QVariant m_accelZ;

    QList<QObject*> m_services;
    QBluetoothDeviceInfo m_dev_info;
};

#endif // BleModelItem_H
