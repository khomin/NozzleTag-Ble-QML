#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleModel = new BleModel();
    ble = new Ble(bleModel);

    connect(ble, &Ble::scanStarted, this, &Application::bleScanStarted);
    connect(ble, &Ble::scanFinishedSignal, this, &Application::bleScanFinished);
    connect(ble, &Ble::bleServieCharactresticsUpdated, this, &Application::bleServieCharactresticsUpdated);
}

void Application::bleStartScann() {
    ble->startScan();
}

void Application::bleStopScann() {
    ble->stopScan();
}

BleModel* Application::getBleModel() {
    return bleModel;
}
