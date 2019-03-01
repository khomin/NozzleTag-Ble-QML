#ifndef BLEDEVICE_H
#define BLEDEVICE_H

#include <QObject>
#include <QBluetoothDeviceInfo>

class BleDevice : public QObject
{
    Q_OBJECT
public:
    BleDevice(const QString devName, const QString devAddr, const QBluetoothDeviceInfo deviceInfo);

    QString getDevName();
    QString getDevAddr();
    QBluetoothDeviceInfo getDevInfo();
private:
    QString devName;
    QString devAddr;
    QBluetoothDeviceInfo deviceInfo;

};

#endif // BLEDEVICE_H
