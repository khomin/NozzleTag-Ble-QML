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

    property bool scanIsRunner: false

    Connections {
        target:application
        onBleScanStarted: {
            scanIsRunner = true;
        }
        onBleScanFinished: {
            scanIsRunner = false;
       }
    }

    Component.onCompleted: {
        application.bleStartScann()
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
                    enabled: !scanIsRunner
                    onClicked: {
                        application.bleStartScann();
                    }
                }
                Rectangle {width: 5; height: 5}
                Button {
                    id:stopScanning
                    widthBody: panelRectangle.width / 2 - 15
                    caption: "Stop"
                    enabled: scanIsRunner
                }
            }
            ListView {
                id: mainList
                width: parent.width - 10
                height: panelRectangle.height - buttonStanRow.height - busyRectangle.height - 15
                clip: true
                enabled: !scanIsRunner

                model: bleDeviceModel
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
                            text: model.devName + " " + model.devRssi
                            font.family: "FreeSerif"
                            font.pointSize: 12
                            color: "#ff5c00"// : "black";
                        }

                        Text {
                            id: details
                            visible: opacity !== 0
                            opacity: 1
                            text: model.devAddr
                            font.family: "FreeSerif"
                            font.pointSize: 14
                            color: "#ff5c00" //: "black";
                            Behavior on opacity {
                                NumberAnimation { duration: 200}
                            }
                        }
                    }
                    Behavior on height { NumberAnimation { duration: 200} }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            application.bleStartScann()
                        }
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
                visible: scanIsRunner
                Text {
                    id: text
                    text: "Scanning"
                    font.bold: true
                    font.pointSize: 20
                    anchors.horizontalCenter: parent.horizontalCenter                }
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
