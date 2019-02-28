#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleApi = new BleApi();
    connect(bleApi, &BleApi::scanStarted, this, &Application::bleScanStarted);
    connect(bleApi, &BleApi::scanFinishedSignal, this, &Application::bleScanFinished);
    connect(bleApi, &BleApi::bleServieCharactresticsUpdated, this, &Application::bleServieCharactresticsUpdated);
}

void Application::bleStartScann() {
    emit bleClearDeviceData();
    bleApi->startScan();
}

void Application::bleStopScann() {
//    bleDevice->sta();
}

BleModel* Application::getBleModel() {
    return bleApi->getBleModel();
}
