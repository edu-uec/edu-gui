import QtQuick 2.0
import QtQuick.Shapes 1.11

Item{
    id: _root
    property int lastFace: 0

    property variant faceIds: [normal_face, smile_face]

    Shape {
        id: normal_face;
        width: parent.width;
        height: parent.height;
        visible: true

        property int faceAmplitude: 10
        property int animeDurationAdjustment: 12

        property double rightEyePosX: 0.4
        property double leftEyePosX: 0.6



        //同じShapeObject内でアニメーションを重ねがけすると何故か実行スピードが倍数で上昇するので計測の結果分かった倍率をdurationにかけている
        ParallelAnimation {
            running: true
            SequentialAnimation{
                loops: Animation.Infinite
                NumberAnimation {target: normal_face; property: "y"; from: normal_face.y - normal_face.faceAmplitude; to: normal_face.y + normal_face.faceAmplitude; easing.type: Easing.InOutCirc; duration: 3000 * normal_face.animeDurationAdjustment }
                NumberAnimation {target: normal_face; property: "y"; from: normal_face.y + normal_face.faceAmplitude; to: normal_face.y - normal_face.faceAmplitude; easing.type: Easing.InOutCirc; duration: 3000 * normal_face.animeDurationAdjustment }
            }

            SequentialAnimation {
                loops: Animation.Infinite
                PauseAnimation { duration: 4200 * normal_face.animeDurationAdjustment }
                NumberAnimation { targets: [normal_right_eye, normal_left_eye]; property: "startY"; from: normal_face.height * 0.3; to: normal_face.height * 0.5; duration: 200 * normal_face.animeDurationAdjustment }
                NumberAnimation { targets: [normal_right_eye, normal_left_eye]; property: "startY"; from: normal_face.height * 0.5; to: normal_face.height * 0.3; duration: 300 * normal_face.animeDurationAdjustment}
            }
        }

        ShapePath {
            id: normal_right_eye
            strokeWidth: 5
            strokeColor: "black"
            fillColor: "transparent"

            startX: normal_face.width * normal_face.rightEyePosX;
            startY: normal_face.height * 0.3

            PathLine { x: normal_face.width * normal_face.rightEyePosX; y: normal_face.height * 0.5 }
        }

        ShapePath {
            id: normal_left_eye
            strokeWidth: 5
            strokeColor: "black"
            fillColor: "transparent"

            startX: normal_face.width * normal_face.leftEyePosX;
            startY: normal_face.height * 0.3
            PathLine { x: normal_face.width * normal_face.leftEyePosX; y: normal_face.height * 0.5 }
        }

        ShapePath {
            id: normal_mouth
            strokeColor: "black"
            strokeWidth: 5
            capStyle: ShapePath.RoundCap
            fillColor: "transparent"

            startX: normal_face.width * 0.2; startY: normal_face.height * 0.6;
            PathCurve { x: normal_face.width * 0.5; y: normal_face.height * 0.7; }
            PathCurve { x: normal_face.width * 0.8; y: normal_face.height * 0.6; }
        }




    }

    Shape {
        id: smile_face;
        width: parent.width;
        height: parent.height;
        visible: false

        property int faceAmplitude: 10
        property int animeDurationAdjustment: 1

        property double rightEyePosX: 0.38
        property double leftEyePosX: 0.62
        property double eyesWidth: smile_face.width * 0.1
        property double eyesHeight: smile_face.height * 0.3

        ParallelAnimation {
            running: true
            SequentialAnimation{
                loops: Animation.Infinite
                NumberAnimation {target: smile_face; property: "y"; from: smile_face.y - smile_face.faceAmplitude; to: smile_face.y + smile_face.faceAmplitude; easing.type: Easing.InOutCirc; duration: 4000 * smile_face.animeDurationAdjustment }
                NumberAnimation {target: smile_face; property: "y"; from: smile_face.y + smile_face.faceAmplitude; to: smile_face.y - smile_face.faceAmplitude; easing.type: Easing.InOutCirc; duration: 4000 * smile_face.animeDurationAdjustment }
            }
        }

        property double cheekRx: smile_face.width * 0.07
        property double cheekRy: smile_face.height * 0.04
        property color cheekColor: "#ff7270"
        property double cheekPx: 0.18
        property double cheekPy: 0.55

        ShapePath{
            fillColor: smile_face.cheekColor
            startX: smile_face.width * smile_face.cheekPx - smile_face.cheekRx; startY: smile_face.height * smile_face.cheekPy
            PathArc {
                x: smile_face.width * smile_face.cheekPx + smile_face.cheekRx; y: smile_face.height * smile_face.cheekPy
                radiusX: smile_face.cheekRx; radiusY: smile_face.cheekRy
            }
        }
        ShapePath{
            fillColor: smile_face.cheekColor
            startX: smile_face.width * smile_face.cheekPx - smile_face.cheekRx; startY: smile_face.height * smile_face.cheekPy
            PathArc {
                x: smile_face.width * smile_face.cheekPx + smile_face.cheekRx; y: smile_face.height * smile_face.cheekPy
                radiusX: smile_face.cheekRx; radiusY: smile_face.cheekRy
                direction: PathArc.Counterclockwise
            }
        }
        ShapePath{
            fillColor: smile_face.cheekColor
            startX: smile_face.width * (1.0 - smile_face.cheekPx) - smile_face.cheekRx; startY: smile_face.height * smile_face.cheekPy
            PathArc {
                x: smile_face.width * (1.0 - smile_face.cheekPx) + smile_face.cheekRx; y: smile_face.height * smile_face.cheekPy
                radiusX: smile_face.cheekRx; radiusY: smile_face.cheekRy
            }
        }
        ShapePath{
            fillColor: smile_face.cheekColor
            startX: smile_face.width * (1.0 - smile_face.cheekPx) - smile_face.cheekRx; startY: smile_face.height * smile_face.cheekPy
            PathArc {
                x: smile_face.width * (1.0 - smile_face.cheekPx) + smile_face.cheekRx; y: smile_face.height * smile_face.cheekPy
                radiusX: smile_face.cheekRx; radiusY: smile_face.cheekRy
                direction: PathArc.Counterclockwise
            }
        }


        ShapePath {
            id: smile_mouth
            strokeColor: "black"
            //fillColor: "red"
            strokeWidth: 5
            capStyle: ShapePath.RoundCap
            fillColor: "transparent"

            startX: smile_face.width * 0.2; startY: smile_face.height * 0.6;
            PathCubic {
                x: smile_face.width * 0.8; y: smile_face.height * 0.6;
                control1X: smile_face.width * 0.5; control1Y: smile_face.height * 0.8;
                control2X: smile_face.width * 0.5; control2Y: smile_face.height * 0.8;
            }
        }

        ShapePath {
            id: smile_right_eye
            strokeWidth: 5
            strokeColor: "black"
            fillColor: "transparent"

             startX: smile_face.width * smile_face.rightEyePosX - smile_face.eyesWidth / 2;
             startY: smile_face.eyesHeight + smile_face.height * 0.2
             PathQuad {
                    controlX: smile_face.width * smile_face.rightEyePosX; controlY: smile_face.height * 0.2;
                    x: smile_face.width * smile_face.rightEyePosX + smile_face.eyesWidth / 2; y: smile_face.eyesHeight + smile_face.height * 0.2 }

        }

        ShapePath {
            id: smile_left_eye
            strokeWidth: 5
            strokeColor: "black"
            fillColor: "transparent"

            startX: smile_face.width * smile_face.leftEyePosX - smile_face.eyesWidth / 2;
            startY: smile_face.eyesHeight + smile_face.height * 0.2
            PathQuad {
                   controlX: smile_face.width * smile_face.leftEyePosX; controlY: smile_face.height * 0.2;
                   x: smile_face.width * smile_face.leftEyePosX + smile_face.eyesWidth / 2; y: smile_face.eyesHeight + smile_face.height * 0.2 }
        }



    }

    function changeFace(index){
        onFace(index)
        offFace(lastFace)
        lastFace = index
    }

    function offFace(index){
        faceIds[index].visible = false
    }

    function onFace(index){
        faceIds[index].visible = true
    }
}

