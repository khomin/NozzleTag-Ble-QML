#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleDeviceModel = std::make_shared<BleModelDevice>();
    bleServiceModel = std::make_shared<BleModelService>();

    ble = std::make_shared<Ble>(bleDeviceModel.get(), bleServiceModel.get());

    connect(ble.get(), &Ble::scanStarted, this, &Application::bleScanStarted);
    connect(ble.get(), &Ble::scanFinishedSignal, this, &Application::bleScanFinished);
    connect(ble.get(), &Ble::bleServieCharactresticsUpdated, this, &Application::bleServieCharactresticsUpdated);
}

void Application::bleStartScann() {
    ble->startScan();
}

BleModelDevice* Application::getBleModelDevice() {
    return bleDeviceModel.get();
}

BleModelService* Application::getBleModelServices() {
    return bleServiceModel.get();
}
