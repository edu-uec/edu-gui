import QtQuick 2.00
import QtQuick.Window 2.10
import QtQuick.Controls 1.4
import QtQuick.Shapes 1.11

Window {
    visible: true
    id: _root
    width: 480
    height: 320

    Rectangle{
        id: code_sheet_bg
        x: parent.width * 0.4;
        width: parent.width * 0.6;
        height: parent.height;
        color:"#ffdddd";
    }

    property int dlgNumber: 0
    property bool isRun: false
    signal qmlSignal(string msg); //定義では型を指定する必要がある。

    function addBlock(text) {
        console.log("add as dlgnum = " + dlgNumber);
        _repeater.model.append({"_src" : _dlg});
    }

    function deleteBlock() {
        dlgNumber--;
        console.log("delete as dlgnum = " + dlgNumber);
        _repeater.model.remove(dlgNumber);
    }

    function changeBlockColor(index, color){
        console.log("change color as dlgnum = " + index);
    }

    EduMessageWindow{
        id: edu_message
        width: parent.width * 0.4
        height: parent.height * 0.35
        y: parent.height * 0.65

    }

    EduFace{
        id: edu_face
        width: parent.width * 0.3
        height: parent.width * 0.3
        x: parent.width * 0.05
        y: parent.height * 0.25
    }

    Button {
        text: "-add-"
        visible: false
        onClicked: {
            //コードが実行中でないか
            //            if (!isRun){
            //                addBlock("tes");
            //                qmlSignal("a signal from QML");
            //            }
        }
    }

    Button {
        text: "face"

        onClicked: {
            edu_face.changeFace(edu_face.lastFace === 0 ? 1 : 0)
        }
    }

    Column {
        spacing: 10
        Repeater {
            id: _repeater
            model: ListModel {}
            Loader {
                sourceComponent: _src
                onLoaded: {
                    item.visible = true;
                    dlgNumber++;
                    item.text = orderprogram.getOrderName(index);
                }
            }
        }
    }

    Component {
        id: _dlg
        Dialog {
            property string text
            width: _root.width * 0.4; height: _root.height * 0.2
            x: _root.width * 0.5; y: 10
            d_text: text;
        }
    }
}
