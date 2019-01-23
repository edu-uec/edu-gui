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
        anchors.right: parent.right
        width: parent.width * 0.5;
        height: parent.height;
        color:"#ffdddd";

        ListView {
            id: commandList
            model: commandModel
            spacing: 5
            anchors.fill: parent
            anchors.margins: 20

            delegate: Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60
                opacity: 0.8
                radius: 10
                color: Style.buttonBackground

                Text {
                    text: name
                    font.pointSize: 16
                    color: Style.text
                    anchors.centerIn: parent
                }

                Text {
                    text: index
                    font.pointSize: 16
                    color: Style.text
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                }
            }
        }
    }

    property int dlgNumber: 0
    property bool isRun: false
    property bool visibleMessageWindow: true
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
        width: parent.width * 0.5
        height: parent.height * 0.5
        y: parent.height * 0.5

        visible: visibleMessageWindow
    }

    EduFace{
        id: edu_face
        width: parent.width * 0.3
        height: parent.width * 0.3
        x: parent.width * 0.05
        y: parent.height * 0.07
    }

    Button {
        text: "face"
        width: 40

        onClicked: {
            edu_face.changeFace(edu_face.lastFace === 0 ? 1 : 0)
        }
    }

    Button {
        text: "mes"
        x : 40
        width: 40
        onClicked: {
            if(visibleMessageWindow){
                visibleMessageWindow = false
                edu_face.y = parent.height * 0.25
            }else{
                visibleMessageWindow = true
                edu_face.y = parent.height * 0.07
            }
        }
    }

    Button {
        text: "add"
        x : 80
        width:40

        onClicked: {
            commandModel.addCommandFromName("Go")
        }
    }

    Button {
        text: "remove"
        x : 120
        width:80

        onClicked: {
            commandModel.removeRows(commandModel.rowCount()-1 , 1) //remove last element
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
        CommandDialog {
            property string text
            width: _root.width * 0.4; height: _root.height * 0.2
            x: _root.width * 0.5; y: 10
            d_text: text;
        }
    }
}
