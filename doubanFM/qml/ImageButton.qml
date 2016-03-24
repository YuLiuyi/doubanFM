import QtQuick 2.0

Rectangle{

    property string source1: ""
    property string source2: ""
    property int imageMargin: 0
    property alias imageWidth: image.width
    property alias imageHeight: image.height
    property bool clickable: true

    signal clicked()

    color: "transparent"
    width: image.width + imageMargin
    height: image.height + imageMargin

    Image {
        id:image
        anchors.centerIn: parent
        source: source1
        width: sourceSize.width
        height: sourceSize.height
        fillMode: Image.PreserveAspectFit
        opacity: !clickable ? 0.3 : mouseArea.pressed ? 0.6 : 1
        Behavior on opacity {
            NumberAnimation {
                duration: 150
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: clickable
        onClicked: {
            parent.clicked()
        }
    }

    states: [
        State {
            name: "pressed"
            when: mouseArea.pressed
            PropertyChanges {
                target: image
                source: source2 === "" ? source1 : source2
            }
        }
    ]

}
