import QtQuick 2.00
import QtQuick.Window 2.10
import QtQuick.Controls 1.4


Window {
    visible: true
    id: _root
    width: 640
    height: 480

    property int dlgNumber: 0
    signal qmlSignal(string msg);
    function showBlock(text) {
        console.log("dlgNumber is " + dlgNumber);
        if (dlgNumber > 6) {
            dlgNumber = 0;
            _repeater.model.clear();
        } else {
            _repeater.model.append({"_src" : _dlg});
        }
    }
        Button {
            text: "button"
            onClicked: {
                qmlSignal("a signal from QML");
            }
        }

    Row {
        Repeater {
           id: _repeater
           model: ListModel {}
           Loader {
               sourceComponent: _src
               onLoaded: {
                   item.visible = true;
                   dlgNumber++;
               }
           }
        }
    }
    Component {
        id: _dlg
        Dialog {
            width: 70; height: 50
            x: calcX(); y: calcY()
            text: "BLOCK"
        }
    }
    function calcX() {
        return 50;
    }
    function calcY() {
        return 50;
    }

}
