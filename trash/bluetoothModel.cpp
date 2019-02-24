#include "bluetoothModel.h"

BluetoothModel::BluetoothModel(QObject *parent) {

}

QHash<int, QByteArray> BluetoothModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
