#ifndef BLEMODEL_SERVICE_ITEM_H
#define BLEMODEL_SERVICE_ITEM_H

#include <QObject>

class BleModelServiceItem : public QObject
{
    Q_OBJECT
public:
    BleModelServiceItem() {}
    BleModelServiceItem(QString name, QString uuid, QString valueHex, QString valueAsci);

    QString getName() const;
    QString getUuid() const;
    QString getValueHex() const;
    QString getValueAsci() const;
    QString setName(QString name);
    QString setUuid(QString uuid);
    QString setValueHex(QString valueHex);
    QString setValueAsci(QString valueAsci);

private:
    QString m_name;
    QString m_uuid;
    QString m_value_hex;
    QString m_value_asci;
};

#endif // BLEMODEL_SERVICE_ITEM_H
