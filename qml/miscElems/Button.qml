import QtQuick 2.4
import QtQuick.Controls 2.2

Button {
    id:standardButton
    property string caption: caption
    property int widthBody: 100
    width: widthBody
    height: 35
    background: Rectangle {
        height: 35
        width: widthBody
        radius: 10
        color: enabled ? (standardButton.checked ? "#a3ff7b" : "#f26b3a")  : "#464646"
        border.color: "#f26b00"
        border.width: 2
        Text {
            id:labelCaption
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: standardButton.checked ? "black" : "white"
            font.pointSize: 10
            text: qsTr(caption)
        }
    }
}
