/*************************************************************************************
** The MIT License (MIT)
**
** BluetoothModel is a free Qt and QML based component.
** Copyright (c) 2017 Arun PK
** Email: mailztopk@gmail.com
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
************************************************************************************/

#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QVector>
#include <QPair>

class BluetoothModel : public QObject
{
    Q_OBJECT
public:
    BluetoothModel(QString devName, QString devAddr);

    Q_PROPERTY(QString devName READ getDevName WRITE setDevName NOTIFY isDevNameChanged)
    Q_PROPERTY(QString devAddr READ getDevAddr WRITE setDevAddr NOTIFY isDevAddrChanged)

    QString getDevName();
    void setDevName(QString value);

    QString getDevAddr();
    void setDevAddr(QString value);


signals:
    void isDevNameChanged();
    void isDevAddrChanged();

private:
    QString m_devName;
    QString m_devAddr;
};

#endif // BluetoothModel_H
