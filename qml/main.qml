import QtQuick 2.0
import com.syberos.basewidgets 2.0

CPageStackWindow {
    initialPage:CPage{

        property int c_index: 0

        id: mainPg
        anchors.fill: parent
        color: "#e2dbdb"
        Component.onCompleted: {
            console.log("component completed.")
            contrl.getChannelInfoReq();
        }

        Rectangle {
            id: rect
            anchors.top: parent.top
            anchors.topMargin: 40
            width: parent.width
            height: 60
            color: "#7a6767"
            Text {
                color: "#5a3939"
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 40
                font.bold: true
                text: "FM"
            }
        }

        ListView {
            id: view
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: rect.bottom
            anchors.bottom: parent.bottom
            model: channelListModel
            clip: true

            delegate: Rectangle {
                id: _delegate
                width: view.width
                height: 80

                Rectangle {
                    id: decorateLine
                    color: gUiConst.getValue("CL1")
                    height: 2
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.right: parent.right
                    anchors.rightMargin: 40
                }


                Text {
                    id: titleTxtInfo
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    text:  name + " MHz"
                    font.family: "汉仪宋体"
                    color: "#7a5555"
                    font.pixelSize:  30
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft       
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mainPg.c_index = index
                        var cid = channelListModel.getChannel_id(index);
                        var sid = channelListModel.getSeq_id(index);
                        contrl.getMusicReq(cid, sid)
                    }
                }
            }
        }

        Connections{
            target: contrl
            onGetInfoFinished :{
                console.log("getInfofinished");
                console.log("playUrl = "+contrl.showMusic(1))

//                var picture = contrl.showMusic(0);
//                var playUrl = contrl.showMusic(1);
//                var title = contrl.showMusic(2);
//                var public_time = contrl.showMusic(3);
//                var singerId = contrl.showMusic(4);
//                var singer = contrl.showMusic(5);
//                var albumtitle = contrl.showMusic(6);
//                var ssid = contrl.showMusic(7);
//                var like = contrl.showMusic(8);
                pageStack.push("qrc:///qml/FM.qml",
                               {channelName: channelListModel.getName(mainPg.c_index),
                               picture: contrl.showMusic(0), playUrl: contrl.showMusic(1), title: contrl.showMusic(2), public_time: contrl.showMusic(3),
                               singerId: contrl.showMusic(4), singer: contrl.showMusic(5), albumtitle: contrl.showMusic(6), ssid:contrl.showMusic(7), like: contrl.showMusic(8)});
            }
        }
    }
}

