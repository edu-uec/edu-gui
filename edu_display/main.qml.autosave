import QtQuick 2.00
import QtQuick.Window 2.10
import QtQuick.Controls 1.4
import QtQuick.Shapes 1.11

Window {
    visible: true
    id: _root
    width: 640
    height: 480

    Rectangle{
        id: code_sheet_bg
        x: parent.width * 0.4;
        width: parent.width * 0.6;
        height: parent.height
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
        //_repeater.model
        console.log("change color as dlgnum = " + index);
    }


    Shape {
        id: edu_face;
        y: 100;
        width: 250;
        height: 250;

        ShapePath {
                id: edu_right_eye
                strokeWidth: 5
                strokeColor: "black"
                fillColor: "transparent"

                startX: edu_face.width * edu_face.getRightEyePosX();
                SequentialAnimation on startY {
                                loops: Animation.Infinite
                                NumberAnimation { from: edu_face.height * 0.3; to: edu_face.height * 0.3; duration: 5000 }
                                NumberAnimation { from: edu_face.height * 0.3; to: edu_face.height * 0.5; duration: 500 }
                                NumberAnimation { from: edu_face.height * 0.5; to: edu_face.height * 0.3; duration: 1000 }
                            }
                PathLine { x: edu_face.width * edu_face.getRightEyePosX(); y: edu_face.height * 0.5 }
        }

        ShapePath {
                id: edu_left_eye
                strokeWidth: 5
                strokeColor: "black"
                fillColor: "transparent"

                startX: edu_face.width * edu_face.getLeftEyePosX();
                SequentialAnimation on startY {
                                loops: Animation.Infinite
                                NumberAnimation { from: edu_face.height * 0.3; to: edu_face.height * 0.3; duration: 5000 }
                                NumberAnimation { from: edu_face.height * 0.3; to: edu_face.height * 0.5; duration: 500 }
                                NumberAnimation { from: edu_face.height * 0.5; to: edu_face.height * 0.3; duration: 1000 }
                            }
                PathLine { x: edu_face.width * edu_face.getLeftEyePosX(); y: edu_face.height * 0.5 }
        }



        ShapePath {
                id: edu_mouth
                strokeColor: "black"
                strokeWidth: 5
                capStyle: ShapePath.RoundCap

                startX: edu_face.width * 0.2; startY: edu_face.height * 0.6;
                PathCubic {
                    x: edu_face.width * 0.8; y: edu_face.height * 0.6;
                    control1X: edu_face.width * 0.5; control1Y: edu_face.height * 0.8;
                    control2X: edu_face.width * 0.5; control2Y: edu_face.height * 0.8;
                }
            }

        function getRightEyePosX(){
            return 0.6;
        }
        function getLeftEyePosX(){
            return 0.4;
        }

    }

    Button {
        text: "-add-"

        onClicked: {
            //コードが実行中でないか
            if (!isRun){
                //addBlock("tes");
                //qmlSignal("a signal from QML");
            }
        }
    }

    Button {
        text: "-run-"
        y: 30

        onClicked: {
            isRun = true;
            //showBlock("tes");
            //qmlSignal("a signal from QML");
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
            width: 160; height: 60
            x: calcX(); y: calcY()
            d_text: text;
        }
    }

    function calcX() {
        return 320;
    }
    function calcY() {
        return 10;
    }

}

