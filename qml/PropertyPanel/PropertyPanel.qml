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
import "qrc:/qml/qml/miscElems/"

Item {
    id: projectDeviceScreen

    Connections {
        target:application
        onBleServieCharactresticsUpdated: {
            listPropertyDescInfoListModel.append({"serviceName":serviceName,"uuid":uuid,"value":value});
        }
    }

//    Component.onCompleted: {
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//        listPropertyDescInfoListModel.append({"serviceName":"serviceName","uuid":"uuid","value":"value"});
//    }

    Rectangle {
        id: devicePanel
        color: "#ffffff"
        anchors.fill: parent

        Column {
            anchors.fill: parent
            spacing: 20

            Rectangle {
                id: rssiRect
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
            TabBar {
                id:tabProperty
                height: 25
                anchors.left: parent.left
                anchors.leftMargin: 30
                currentIndex: 0
                font.pointSize: 8
                background: Rectangle {
                    color: "#ffffff"
                }
                TabButtonUp {
                    id:tabItemProperty
                    name: "Property"
                    textLine:1
                    widthBody: 150
                }
                TabButtonUp {
                    id:tabItemInfoDescriptor
                    name: "info descriptor"
                    widthBody: 250
                }
                onCurrentIndexChanged: {
                    swipeProperty.setCurrentIndex(tabProperty.index)
                }
            }
            SwipeView {
                id: swipeProperty
                width: parent.width
                height: parent.height - rssiRect.height
                currentIndex: tabProperty.currentIndex
                Item {
                    ScrollView {
                        clip: true
                        anchors.fill: parent
                        Rectangle {
                            color: "white"
                            height: parent.height
                            width: parent.width

                            ListView {
                                id: listPropertyDescInfo
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
                                    height: 75
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
                                            Label {
                                                text: model.serviceName
                                            }
                                            Label {
                                                text: model.uuid
                                            }
                                            Label {
                                                text: model.value
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
                                model: ListModel {
                                    id: listPropertyDescInfoListModel
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
