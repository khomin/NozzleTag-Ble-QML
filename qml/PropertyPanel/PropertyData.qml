import QtQuick 2.0
import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.10
import Qt.labs.platform 1.0
import QtCharts 2.2
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.2
import QtQml.Models 2.11

ScrollView {
    clip: true
    anchors.fill: parent
    Rectangle {
        color: "white"
        height: parent.height
        width: parent.width

        ListView {
            id: listPropertyDescInfo
            model: bleDeviceModel
            clip: true
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            spacing: 10

            ScrollBar.vertical: ScrollBar {
                width: 20
            }

            delegate: Item {
                id: listPropertyDescInfoDelegate
                height: 150
                width: parent.width
                Rectangle {
                    id:rectService
                    anchors.fill: parent
                    color: "white"
                    Column {
                        anchors.left: parent.left
                        anchors.leftMargin: 15
                        anchors.right: parent.right
                        anchors.rightMargin: 15
                        anchors.top: parent.top
                        anchors.topMargin: 15
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 15
                        spacing: 5
                        TextField {
                            text: "Accel-X: " + model.accelX
                            width: parent.width
                            height: 25
                        }
                        TextField {
                            text: "Accel-Y: " + model.accelY
                            width: parent.width
                            height: 25
                        }
                        TextField {
                            text: "Accel-Z: " + model.accelZ
                            width: parent.width
                            height: 25
                        }
                    }
                }
                DropShadow {
                    anchors.fill: rectService
                    horizontalOffset: 3
                    verticalOffset: 3
                    radius: 8.0
                    samples: 17
                    color: "#80000000"
                    source: rectService
                }
            }
        }
    }
}
