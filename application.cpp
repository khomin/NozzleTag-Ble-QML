#include "application.h"

Application::Application(QObject *parent) : QObject(parent) {
    bleApi = new BleApi();
    connect(bleApi, &BleApi::scanFinishedSignal, this, [&]() {
        emit bleScanFinished();
    });

    connect(bleApi, &BleApi::bleServieCharactresticsUpdated, this, &Application::bleServieCharactresticsUpdated);
}

void Application::bleStartScann() {
//    bleDevice->startScan();
}

void Application::bleStopScann() {
//    bleDevice->sta();
}

BleModel* Application::getBleModel() {
    return bleApi->getBleModel();
}

bool Application::getScanningIsRunning() {
    return bleApi->getScanningIsRunning();
}
