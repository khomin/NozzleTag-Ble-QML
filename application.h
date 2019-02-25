#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include "./source/bluetooth/BleApi.h"
#include "./source/bluetooth/bleModel.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void bleStartScann();
    Q_INVOKABLE void bleStopScann();
    Q_INVOKABLE bool getScanningIsRunning();
    Q_INVOKABLE BleModel* getBleModel();

signals:
    void bleScanFinished();
    void bleServieCharactresticsUpdated(QString serviceName, QString uuid, QString value);
public slots:

private:
    BleApi* bleApi;
};

#endif // APPLICATION_H
