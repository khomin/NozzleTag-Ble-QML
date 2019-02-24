#ifndef BLUETOOTHMODEL_H
#define BLUETOOTHMODEL_H

#include <QObject>
#include <QAbstractListModel>

class BluetoothModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit BluetoothModel(QObject *parent = nullptr);

    enum BluetoothRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    QHash<int, QByteArray> roleNames() const override;
    int rowCount() const;

signals:

public slots:
};

#endif // BLUETOOTHMODEL_H
