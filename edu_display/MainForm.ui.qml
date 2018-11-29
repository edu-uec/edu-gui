import QtQuick 2.4

Rectangle {
    id: rectangle
    property alias mouseArea: mouseArea

    width:  360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Text {
        anchors.centerIn: parent
        text: "hello world"
    }
}
