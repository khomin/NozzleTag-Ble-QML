import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.10
import Qt.labs.platform 1.0
import QtCharts 2.2
import QtQuick.Controls 1.4 as ControlOld
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.2
import QtQml.Models 2.11

Item {
    id: projectDeviceScreen

    Rectangle {
        id: devicePanel
        color: "#ffffff"
        anchors.fill: parent

        Column {
            anchors.fill: parent
            spacing: 10

            Rectangle {
                width: parent.width
                height: 50
                color: "gray"
                Row {
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    anchors.right: parent.right
                    spacing: 15
                    Text {
                        id: rssiText
                        text: qsTr("RSSI")
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    ProgressBar {
                        id:rssiPb
                        width: parent.width - rssiText.width - 50
                        height: 40
                        anchors.verticalCenter: parent.verticalCenter
                        value: 0
                    }
                }
            }
        }
    }
}
