import QtQuick 2.0
import QtBluetooth 5.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Window 2.2
import "qrc:/qml/qml/miscElems/"

Item {
    id: top
    property BluetoothService currentService

    BluetoothDiscoveryModel {
        id: btModel
        running: true
        discoveryMode: BluetoothDiscoveryModel.DeviceDiscovery
        onDiscoveryModeChanged: console.log("Discovery mode: " + discoveryMode)
        onServiceDiscovered: console.log("Found new service " + service.deviceAddress + " " + service.deviceName + " " + service.serviceName);
        onDeviceDiscovered: console.log("New device: " + device)
        onErrorChanged: {
            switch (btModel.error) {
            case BluetoothDiscoveryModel.PoweredOffError:
                console.log("Error: Bluetooth device not turned on"); break;
            case BluetoothDiscoveryModel.InputOutputError:
                console.log("Error: Bluetooth I/O Error"); break;
            case BluetoothDiscoveryModel.InvalidBluetoothAdapterError:
                console.log("Error: Invalid Bluetooth Adapter Error"); break;
            case BluetoothDiscoveryModel.NoError:
                break;
            default:
                console.log("Error: Unknown Error"); break;
            }
        }
    }

    Rectangle {
        id:panelRectangle
        color: "#fafafa"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 5
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        Rectangle {
            anchors.right: parent.right
            height: parent.height
            width: 10
            color: "#ececec"
        }
        Column {
            anchors.fill: parent
            spacing: 15
            Row {
                id:buttonStanRow
                Button {
                    id:startScanning
                    widthBody: panelRectangle.width / 2 - 10
                    caption: "Start scanning"
                    enabled: !btModel.running
                    onClicked: {
                        btModel.running = true
                        btModel.discoveryMode = BluetoothDiscoveryModel.DeviceDiscovery
                    }
                }
                Rectangle {width: 5; height: 5}
                Button {
                    id:stopScanning
                    widthBody: panelRectangle.width / 2 - 15
                    caption: "Stop"
                    enabled: btModel.running
                    onClicked: {
                        btModel.running = false
                        btModel.discoveryMode = BluetoothDiscoveryModel.DeviceDiscovery
                    }
                }
            }
            ListView {
                id: mainList
                width: parent.width - 10
                height: panelRectangle.height - buttonStanRow.height - busyRectangle.height - 15
                clip: true

                model: btModel
                delegate: Rectangle {
                    id: btDelegate
                    width: parent.width
                    height: column.height + 10
                    property bool expended: true;
                    clip: true
                    Image {
                        id: bticon
                        source: "qrc:/images/images/default.png";
                        width: bttext.height;
                        height: bttext.height;
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.margins: 5
                    }
                    Column {
                        id: column
                        anchors.left: bticon.right
                        anchors.leftMargin: 5
                        Text {
                            id: bttext
                            text: deviceName ? deviceName : name
                            font.family: "FreeSerif"
                            font.pointSize: 12
                        }

                        Text {
                            id: details
                            function get_details(s) {
                                if (btModel.discoveryMode == BluetoothDiscoveryModel.DeviceDiscovery) {
                                    //We are doing a device discovery
                                    var str = remoteAddress;
                                    return str;
                                } else {
                                    var str = "Address: " + s.deviceAddress;
                                    if (s.serviceName) { str += "<br>Service: " + s.serviceName; }
                                    if (s.serviceDescription) { str += "<br>Description: " + s.serviceDescription; }
                                    if (s.serviceProtocol) { str += "<br>Protocol: " + s.serviceProtocol; }
                                    return str;
                                }
                            }
                            visible: opacity !== 0
                            opacity: 1
                            text: get_details(service)
                            font.family: "FreeSerif"
                            font.pointSize: 14
                            Behavior on opacity {
                                NumberAnimation { duration: 200}
                            }
                        }
                    }
                    Behavior on height { NumberAnimation { duration: 200} }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: btDelegate.expended = !btDelegate.expended
                    }
                }
                focus: true
            }
            Rectangle {
                id: busyRectangle
                width: parent.width - 10
                height: 50
                radius: 5
                color: "#1c56f3"
                visible: btModel.running
                Text {
                    id: text
                    text: "Scanning"
                    font.bold: true
                    font.pointSize: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                SequentialAnimation on color {
                    id: busyThrobber
                    ColorAnimation { easing.type: Easing.InOutSine; from: "#1c56f3"; to: "white"; duration: 1000; }
                    ColorAnimation { easing.type: Easing.InOutSine; to: "#1c56f3"; from: "white"; duration: 1000 }
                    loops: Animation.Infinite
                }
            }
        }
    }
}


//        Row {
//            id: buttonGroup
//            property var activeButton: devButton

//            anchors.bottom: parent.bottom
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.bottomMargin: 5
//            spacing: 10

//            Button {
//                id: fdButton
//                width: top.width/3*0.9
//                //mdButton has longest text
//                height: mdButton.height
//                text: "Full Discovery"
//                onClicked: btModel.discoveryMode = BluetoothDiscoveryModel.FullServiceDiscovery
//            }
//            Button {
//                id: mdButton
//                width: top.width/3*0.9
//                text: "Minimal Discovery"
//                onClicked: btModel.discoveryMode = BluetoothDiscoveryModel.MinimalServiceDiscovery
//            }
//            Button {
//                id: devButton
//                width: top.width/3*0.9
//                //mdButton has longest text
//                height: mdButton.height
//                text: "Device Discovery"
//                onClicked: btModel.discoveryMode = BluetoothDiscoveryModel.DeviceDiscovery
//            }
//        }
