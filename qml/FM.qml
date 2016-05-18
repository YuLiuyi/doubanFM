import QtQuick 2.0
import com.syberos.basewidgets 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0

CPage {
    id: page

    color: "#e2dbdb"
    property string channelName: "channel"
    property string picture: ""//
    property string playUrl: ""
    property string title: ""
    property string public_time: ""
    property string singerId : ""
    property string singer :""
    property string albumtitle:""
    property int ssid :0
    property int like: 0
    property string sid: ""
    property string cid: ""

    contentAreaItem: Item {

        Rectangle {
            id: rect
            anchors.top: parent.top
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
                text: channelName
            }
        }

        Image {
            id: bg
            anchors.fill: parent
            source: picture == "" ? "qrc:/images/res/album_init.jpg":picture
            visible: false
        }

        FastBlur{
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: rect.bottom
            anchors.bottom:parent.bottom
            source: bg
            radius: 70
        }

        RoundImage{
            id:play
            anchors.top: rect.bottom
            anchors.topMargin: 80
            anchors.horizontalCenter: parent.horizontalCenter
            //anchors.fill: parent;
            width:400
            height:400
            source: picture == "" ? "qrc:/images/res/album_init.jpg":picture
            color:"lightblue"
            border:5
        }

        Text {
            id: sname
            color: "#000000"
            //            width: 200
            anchors.top: play.bottom
            anchors.topMargin: 100
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 50
            text: title
            elide: Text.ElideMiddle
            maximumLineCount: 1
            //            wrapMode: Text.WordWrap
            font.family: "Courier New"
        }


        Text {
            id: song
            color: "#696161"
            anchors.top: sname.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 30
            text: singer
            font.family: "Courier New"
        }

        //-------------------控制按钮---------------------------------------
        Row {
            id: ctlpanel
            anchors.top: song.bottom
            anchors.topMargin: 60
            spacing: 100
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: like
                width:  80
                height: 80
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/res/unlike.png"


                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //if like, turn to unlike;else turn to like
                        //if like, it will be added to like list
                    }
                }
            }

            Image {
                id: more
                width:  80
                height: 80
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/res/playlist_more.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        //get more info
                        infoDialog.show()
                    }
                }
            }

            Image {
                id: next
                width:  80
                height: 80
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/res/next.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("next")
                        contrl.getMusicReq(cid,sid,true)
                    }
                }
            }
        }

        Connections {
            target: contrl
            onFreshFinished: {
                console.log("next playUrl = "+ playUrl)
                picture = contrl.showMusic(0);
                playUrl = contrl.showMusic(1);
                title = contrl.showMusic(2);
                public_time = contrl.showMusic(3);
                singerId = contrl.showMusic(4);
                singer = contrl.showMusic(5);
                albumtitle = contrl.showMusic(6);
                //            ssid = contrl.showMusic(7);
                like = contrl.showMusic(8);
                mediaPlayer.play()
            }
        }

        MediaPlayer {
            id: mediaPlayer
            autoPlay: true
            source: playUrl
        }

        CDialog {
            id: infoDialog
            anchors.left: parent.left
            anchors.right: parent.right
            titleText: "详细信息"
            messageAreaComponent: Component {
                Rectangle {
                    //id: infoBG
                    height: 200
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    color: "white"
                    visible: true

                    Column {
                        //id: taginfo
                        anchors.fill: parent
                        spacing: 10
                        Text {
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text : singer == "" ? "歌手: "+"未知" : "歌手: "+singer
                            font.pixelSize: 30
                            color: "#625353"
                        }
                        Text {
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text : albumtitle == "" ? "专辑: "+"未知" : "专辑: "+albumtitle
                            font.pixelSize: 30
                            color: "#625353"
                        }
                        Text {
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text : public_time == "" ? "发行时间: "+"未知" : "发行时间: "+public_time
                            font.pixelSize: 30
                            color: "#625353"
                        }
                    }
                }
            }

            buttonAreaComponent: Component {
                CButton {
                    width: 650
                    height: 95
                    text: "知道了"
                    onClicked: {
                        infoDialog.hide();
                    }
                }
            }
        }

        //-----------------------duration--------------------------------------
        Rectangle {
            id: progressBar
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin:40
            height: 20
            color: "#cad5d2"

            Rectangle {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: player.duration() > 0 ? parent.width * player.position / player.duration() : 0
                color: "#699169"
            }
        }
    }
}
