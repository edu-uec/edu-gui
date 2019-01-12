import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: _root
    radius: 10.0
    color: "white"
    border.color: "gray"
    border.width: 2

    property variant texts: [
        ["text1", 0],
        ["text2", 0],
        ["text1uhfsdksjfhksjfhskjfhkshfkjdsjhfdh", 1],
        ["text3jfdhgdkjshfgjhdkjshgfksjhfgkshdfjkghskjhkdjfhgkjfdksdhfjhgjhfksfjghjkhfkjshdfkgjhkdfjhgkjsdfjkghfkdsjjk", 1]
    ]

    property variant images: [
        "image/qtlogo.png",
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

        source: images[0]
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
            var textsData = texts[index]
            text.text = textsData[0]
            image.source = images[textsData[1]]
            textIndex = index
        }
    }

    function changePrevContents(){
        var index = textIndex - 1
        if(index >= 0){
            var textsData = texts[index]
            text.text = textsData[0]
            image.source = images[textsData[1]]
            textIndex = index
        }
    }

}
