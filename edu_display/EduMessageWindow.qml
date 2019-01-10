import QtQuick 2.0

Rectangle {
    id: _root
    radius: 10.0
    color: "gray"

    Image{
        id: image
        width: parent.width * 0.3
        height: parent.height

        source: "image/qtlogo.png"
    }
    Text{
        id: text
        width: parent.width * 0.7
        height: parent.height
        anchors.left: image.right

        text: "samplesamplesamplesamplesamplesamplesamplesamplesamplesamplesamplesample"
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.Wrap
    }

}
