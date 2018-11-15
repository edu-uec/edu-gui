import QtQuick 2.0
// Dialog.qml

Rectangle {
    id: _root
    width: 300
    height: 150
    opacity: 0.8
    visible: false
    property alias d_text: _text.text //"text:"で_text.textに設定できる

    Text {
        id: _text
        anchors.centerIn: parent
        color: "#ffffff"
        font.pointSize: 14
    }

    Component.onCompleted: {
        var r = Math.random()
        var g = Math.random()
        var b = Math.random()

        _root.color = Qt.rgba(r, g, b, 1.0)
        if ((r + g + b) < 1.5) {
            _text.color = "#ffffff"
        } else {
            _text.color = "#000000"
        }
    }
}
