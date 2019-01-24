import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: _root
    radius: 10.0
    color: "white"
    border.color: "gray"
    border.width: 2

    property variant texts: [
        ["やぁ！僕はEduだよ！", 0],
        ["これから僕と一緒にプログラミングをしよう", -1],
        ["”声”でプログラミングして僕を動かすよ", 1],
        ["まず基本的な操作の方法を教えるね", 1],
        ["僕を前に動かしてみよう", -1],
        ["僕に「前」って言って", -1],
        ["横に”前”というブロックが出てくるよ", -1],
        ["僕に「実行」っていうとブロックの通りに動くよ", -1],
        ["「実行」っていって僕を実際に前に動かして", -1],
        ["他の動きも見てみよう", -1],
        ["僕に「後ろ」って言って", -1],
        ["僕に「実行」って言って動かしてみよう", -1],
        ["後ろに動くことができるよ", -1]
    ]

    property variant images: [
        "image/machineDesign.png",
        "image/pic1.png",
        "image/dog.jpg"
    ]

    property int textIndex: 0

    Image{
        id: image
        width: parent.width * 0.28
        height: parent.height
        x: parent.width * 0.02
        anchors.leftMargin: parent.width * 0.1
        fillMode: Image.PreserveAspectFit

        source: images[texts[0][1]]
    }
    Text{
        id: text
        width: parent.width * 0.66
        height: parent.height
        anchors.left: image.right
        anchors.leftMargin: parent.width * 0.02

        text: texts[0][0]
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.Wrap
    }

    Button{
        x: parent.width * 0.4
        y: parent.height * 0.85
        text: "<"
        onClicked: {
            changePrevContents()
        }
        width: parent.width * 0.1
        height: parent.height * 0.1
    }
    Button{
        x: parent.width * 0.5
        y: parent.height * 0.85
        text: ">"
        onClicked: {
            changeNextContents()
        }
        width: parent.width * 0.1
        height: parent.height * 0.1
    }

    function changeContents(index){
        textsData = texts[index]
        text.text = textsData[0]
        image.source = images[textsData[1]]
    }

    function changeNextContents(){
        var index = textIndex + 1
        if(index < texts.length){
            setContent(texts[index])
            textIndex = index
        }
    }

    function changePrevContents(){
        var index = textIndex - 1
        if(index >= 0){
            setContent(texts[index])
            textIndex = index
        }
    }

    function setContent(textsData){
        if(textsData[1] !== -1){
            image.source = images[textsData[1]]
            image.width = width * 0.28

            text.width = width * 0.66
        }else{
            image.width = 0

            text.width = width * 0.94

        }
        text.text = textsData[0]

    }

}
