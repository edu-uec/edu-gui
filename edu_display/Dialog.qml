import QtQuick 2.0
// Dialog.qml

Rectangle {
    id: _root
    width: 300
    height: 150
    opacity: 0.8

    visible: false
    property alias d_text: _text.text //"text:"で_text.textに設定できる

    states: [
        State {
            name: "Normal"
            PropertyChanges {
                target: _root
                color: "#aaffff"
            }
        },
        State {
            name: "Running"
            PropertyChanges {
                target: _root
                color: "#ffff00"
            }
        }
    ]

    Text {
        id: _text
        anchors.centerIn: parent
        color: "#000000"
        font.pointSize: 14
    }

    Component.onCompleted: {
        _root.state = "Normal"
        _root.radius = 10.0
        _text.color = "#000000"

        /*
        if ((r + g + b) < 1.5) {
            _text.color = "#ffffff"
        } else {
            _text.color = "#000000"
        }
        */
    }
}
