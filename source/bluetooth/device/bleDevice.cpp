#include "bleDevice.h"

BleDevice::BleDevice(const QString devName, const QString devAddr,
                     const QBluetoothDeviceInfo deviceInfo) {
    this->devAddr = devAddr;
    this->devName = devName;
    this->deviceInfo = deviceInfo;
}

QString BleDevice::getDevName() {
    return devName;
}

QString BleDevice::getDevAddr() {
    return devAddr;
}

QBluetoothDeviceInfo BleDevice::getDevInfo() {
    return deviceInfo;
}
