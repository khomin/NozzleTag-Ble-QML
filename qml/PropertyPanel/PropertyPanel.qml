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
            listPropertyDescInfoListModel.append({"serviceName":serviceName,"uuid":uuid,"valueAsci":valueAsci,"valueHex":valueHex});
        }
    }

    Rectangle {
        id: devicePanel
        color: "#ffffff"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15

        Column {
            anchors.fill: parent
            spacing: 20
            TabBar {
                id:tabProperty
                anchors.left: parent.left
                anchors.leftMargin: 30
                currentIndex: 1
                font.pointSize: 8
                background: Rectangle {
                    color: "#ffffff"
                }
                TabButtonUp {
                    id:tabItemProperty
                    name: "Property"
                    textLine:1
                    widthBody: 150
                    height: 20
                }
                TabButtonUp {
                    id:tabItemInfoDescriptor
                    name: "Info descriptor"
                    widthBody: 180
                    height: 20
                }
                onCurrentIndexChanged: {
                    swipeProperty.setCurrentIndex(tabProperty.index)
                }
            }
            SwipeView {
                id: swipeProperty
                width: parent.width
                height: parent.height - tabProperty.height
                currentIndex: tabProperty.currentIndex
                clip: true
                Item {
                    ScrollView {
                        clip: true
                        anchors.fill: parent
                        Rectangle {
                            color: "white"
                            height: parent.height
                            width: parent.width
                        }
                    }
                }
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
                                                text: "Name: " + model.serviceName
                                                width: parent.width
                                                height: 25
                                            }
                                            TextField {
                                                text: "UUID:" + model.uuid
                                                width: parent.width
                                                height: 25
                                            }
                                            TextField {
                                                text: "ASCI: " + model.valueAsci
                                                width: parent.width
                                                height: 25
                                            }
                                            TextField {
                                                text: "HEX: " + model.valueHex
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
