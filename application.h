#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include "./source/bluetooth/ble.h"
#include "./source/bluetooth/bleModelDevice.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void bleStartScann();
    Q_INVOKABLE void bleStopScann();
    Q_INVOKABLE BleModelDevice* getBleModel();

signals:
    void bleScanStarted();
    void bleScanFinished();
    void bleServieCharactresticsUpdated(QString serviceName, QString uuid, QString valueAsci, QString valueHex);

private:
    Ble* ble;
    BleModelDevice* bleModel;
};

#endif // APPLICATION_H
