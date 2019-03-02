#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleDeviceModel = new BleModelDevice();
    bleServiceModel = new BleModelService();

    ble = new Ble(bleDeviceModel, bleServiceModel);

    connect(ble, &Ble::scanStarted, this, &Application::bleScanStarted);
    connect(ble, &Ble::scanFinishedSignal, this, &Application::bleScanFinished);
    connect(ble, &Ble::bleServieCharactresticsUpdated, this, &Application::bleServieCharactresticsUpdated);
}

void Application::bleStartScann() {
    ble->startScan();
}

BleModelDevice* Application::getBleModelDevice() {
    return bleDeviceModel;
}

BleModelService* Application::getBleModelServices() {
    return bleServiceModel;
}
