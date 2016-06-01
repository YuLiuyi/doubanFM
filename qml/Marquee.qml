import QtQuick 2.0

Item {
    id: marquee

    // text to be displayed by the Marquee
    property string text

    // top/bottom text padding
    property int padding : 10

    // the font size used by the Marquee
    property int fontSize : 45

    // the scrolling animation interval
    property int interval : 100

    // the text color
    property color textColor: "black"

    signal clicked();

    Item {
        id: rect
        clip: true
        width: parent.width
        height: marqueeText.height/* + padding*/

        Text {
            id: marqueeText
            anchors.verticalCenter: rect.verticalCenter
            font.pixelSize: fontSize
            color: textColor
            text: marquee.text
            x: rect.width
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
              marquee.clicked()
            }
        }
    }

    Timer {
        interval: parent.interval
        onTriggered: moveMarquee()
        running: true
        repeat: true
    }

    function moveMarquee()
    {
        if(marqueeText.x + marqueeText.width < 0)
        {
            marqueeText.x = marqueeText.parent.width;
        }
        marqueeText.x -= 7;
    }

}
