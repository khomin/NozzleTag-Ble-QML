import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Window 2.2
import "qrc:/qml/qml/leftPanel"
import "qrc:/qml/qml/PropertyPanel"

ApplicationWindow {
    width: 800
    height: 800

    visible: true
    title: "NozzleTag desktop configure"

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("E&xit")
                shortcut: StandardKey.Quit
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Edit")
            MenuItem {
                action: cutAction
            }
            MenuItem {
                action: copyAction
            }
            MenuItem {
                action: pasteAction
            }
        }
        Menu {
            title: qsTr("Help")
            MenuItem {
                text: qsTr("About...")
                onTriggered: aboutDialog.open()
            }
        }
        style: MenuBarStyle {
            padding {
                left: 8
                right: 8
                top: 3
                bottom: 3
            }

            background: Rectangle {
                id: rect
                color: "#3c3b37"
            }

            itemDelegate: Rectangle {            // the menus
                implicitWidth: lab.contentWidth * 1.4           // adjust width the way you prefer it
                implicitHeight: lab.contentHeight               // adjust height the way you prefer it
                color: styleData.selected || styleData.open ? "#ff5c00" : "transparent"
                Label {
                    id: lab
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "white"
                    font.wordSpacing: 10
                    text: styleData.text
                }
            }

            menuStyle: MenuStyle {
                id: goreStyle

                frame: Rectangle {
                    color: "#3c3b37"
                }

                itemDelegate {
                    background: Rectangle {
                        color:  styleData.selected || styleData.open ? "#ff5c00" : "#3c3b37"
                        radius: styleData.selected ? 3 : 0
                    }

                    label: Label {
                        color: "white"
                        text: styleData.text
                    }

                    submenuIndicator: Text {
                        text: "\u25ba"
                        font: goreStyle.font
                        color: styleData.selected  || styleData.open ? "white" : "#ff5c00"
                        styleColor: Qt.lighter(color, 4)
                    }

                    shortcut: Label {
                        color: "white"
                        text: styleData.shortcut
                    }

                    checkmarkIndicator: CheckBox {          // not strinctly a Checkbox. A Rectangle is fine too
                        checked: styleData.checked

                        style: CheckBoxStyle {

                            indicator: Rectangle {
                                implicitWidth: goreStyle.font.pixelSize
                                implicitHeight: implicitWidth
                                radius: 2
                                color: "#ff5c00"
                                border.color: "#ff5c00"
                                border.width: 2
                                Rectangle {
                                    visible: control.checked
                                    color: "#ff5c00"
                                    border.color: menuBackgroundColor
                                    border.width: 2
                                    radius: 2
                                    anchors.fill: parent
                                }
                            }
                            spacing: 10
                        }
                    }
                }
                separator: Rectangle {
                    width: parent.width
                    implicitHeight: 2
                    color: "white"
                }
            }
        }
    }


    Row {
        anchors.fill: parent
        LeftPanel {
            id: leftPanel
            width: parent.width / 3
            height: parent.height
        }
        PropertyPanel {
            id:propertyPanel
            width: parent.width - leftPanel.width
            height: parent.height
        }
    }

    MessageDialog {
        id: aboutDialog
        icon: StandardIcon.Information
        title: qsTr("About")
        text: "Bla Bla message"
        informativeText: qsTr("Bla Bla message")
    }

    Action {
        id: copyAction
        text: qsTr("Copy")
        shortcut: StandardKey.Copy
        iconName: "edit-copy"
        enabled: (!!activeFocusItem && !!activeFocusItem["copy"])
        onTriggered: activeFocusItem.copy()
    }

    Action {
        id: cutAction
        text: qsTr("Cut")
        shortcut: StandardKey.Cut
        iconName: "edit-cut"
        enabled: (!!activeFocusItem && !!activeFocusItem["cut"])
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: qsTr("Paste")
        shortcut: StandardKey.Paste
        iconName: "edit-paste"
        enabled: (!!activeFocusItem && !!activeFocusItem["paste"])
        onTriggered: activeFocusItem.paste()
    }
}
