#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleDeviceModel = new BleModel();
//    connect(bleDevice, &BleDevice::scanFinishedSignal, this, [&]() {
//        emit bleScanFinished();
//    });
}

void Application::bleStartScann() {
//    bleDevice->startScan();
}

void Application::bleStopScann() {
//    bleDevice->sta();
}

BleModel* Application::getBleModel() {
    return bleDeviceModel;
}

bool Application::getScanningIsRunning() {
//    return bleDevice->getScanningIsRunning();
}
