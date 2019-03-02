#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include "./source/bluetooth/ble.h"
#include "./source/bluetooth/device/bleModelDevice.h"
#include "./source/bluetooth/service/bleModelService.h"
#include <memory>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void bleStartScann();
    Q_INVOKABLE BleModelDevice* getBleModelDevice();
    Q_INVOKABLE BleModelService* getBleModelServices();

signals:
    void bleScanStarted();
    void bleScanFinished();
    void bleServieCharactresticsUpdated(QString serviceName, QString uuid, QString valueAsci, QString valueHex);

private:
    std::shared_ptr<Ble> ble;
    std::shared_ptr<BleModelDevice> bleDeviceModel;
    std::shared_ptr<BleModelService> bleServiceModel;
};

#endif // APPLICATION_H
