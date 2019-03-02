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
import "qrc:/qml/qml/miscElems/" as CustomElements
import "qrc:/qml/qml/PropertyPanel/" as PropertyDataItems

Item {
    id: projectDeviceScreen

    Connections {
        target:application
        onBleServieCharactresticsUpdated: {}
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
                currentIndex: 0
                font.pointSize: 8
                background: Rectangle {
                    color: "#ffffff"
                }
                CustomElements.TabButtonUp {
                    id:tabItemProperty
                    name: "Property"
                    textLine:1
                    widthBody: 150
                    height: 20
                }
                CustomElements.TabButtonUp {
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
                    PropertyDataItems.PropertyData {
                        id:propertyDevData
                    }
                }
                Item {
                    PropertyDataItems.PropertyServices {
                        id:propertyServices
                    }
                }
            }
        }
    }
}
