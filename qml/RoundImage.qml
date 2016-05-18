import QtQuick 2.0
import QtQuick.Controls 1.1

import QtQuick.Window 2.0

import QtQuick.Controls.Styles 1.1

import QtGraphicalEffects 1.0


// source from http://www.350351.com/bianchengyuyan/Qt/318159_2.html

//modify for jues 2015-02-03


Item {

    id:mainRect

    property string source: ""

    property color color: "#D74F37"

    property int border:2


    Canvas {

        id: canvas

        width: parent.width; height: parent.height

        property real hue: 0.0


        onPaint: {

            var ctx = getContext("2d")

            ctx.clearRect(0, 0, parent.width, parent.height)

            ctx.lineWidth = border

            // store current context setup

            ctx.save()

            ctx.strokeStyle = color;

            ctx.beginPath()

            ctx.arc(mainRect.width/2, mainRect.height/2, mainRect.width/2, 0, Math.PI * 2, true);

            ctx.closePath()

            ctx.clip()  // create clip from triangle path

            // draw image with clip applied

            ctx.drawImage(source, 0, 0, width, height)

            // draw stroke around path

            ctx.closePath()

            ctx.stroke()

            // restore previous setup

            ctx.restore()

        }


        // jues remove for 2015-02-03

        /*

        Component.onCompleted: {

            loadImage(source);

        }*/


        // jues add for 2015-02-03

        onImageLoaded: {

            mainRect.repaintUI();

        }


    }

    function repaintUI()

    {

        canvas.requestPaint();

    }

    onSourceChanged: {
        console.log("source="+ source)

        canvas.requestPaint()
    }

}
