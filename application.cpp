#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleDevice = new BleDevice();
    connect(bleDevice, &BleDevice::scanFinishedSignal, this, [&]() {
        emit bleScanFinished();
    });
}

void Application::bleStartScann() {
//    bleDevice->startScan();
}

void Application::bleStopScann() {
//    bleDevice->sta();
}

BleModel* Application::getBleModel() {
    return bleDevice->getBleModel();
}

bool Application::getScanningIsRunning() {
//    return bleDevice->getScanningIsRunning();
}
