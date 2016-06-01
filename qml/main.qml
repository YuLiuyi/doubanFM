import QtQuick 2.0
import dataModel 1.0
import com.syberos.basewidgets 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0

import dataModel 1.0

CPageStackWindow {
    initialPage:CPage{
        id: mainPg
        //
        property int c_index: 0
        property string cid: "61"
        //
        property string channelName: "新歌MHz"
        property string picture: ""//
        property string playUrl: ""
        property string title: ""
        property string public_time: ""
        property string singerId : ""
        property string singer :""
        property string albumtitle:""
        property int ssid :0
        property int like: 0
        property string lyric_txt: "value"
        property bool isCurrentItem: true
//        property int  volume: 0

        anchors.fill: parent
        color: "#000"
        Component.onCompleted: {
            console.log("component completed.")
            contrl.getChannelInfoReq();
            contrl.getMusicReq(cid)
        }
        property bool errorFlag: true

        Connections{
            target: contrl
            onFreshFinished: {
                console.log("show playUrl = "+ mainPg.playUrl)
                //                mainPg.show()
                mainPg.errorFlag = true
                mainPg.picture = contrl.showMusic(0);
                mainPg.playUrl = contrl.showMusic(1);
                mainPg.title = contrl.showMusic(2);
                mainPg.public_time = contrl.showMusic(3);
                mainPg.singerId = contrl.showMusic(4);
                mainPg.singer = contrl.showMusic(5);
                mainPg.albumtitle = contrl.showMusic(6);
                if(mainPg.playUrl == "") {
                    contrl.getMusicReq(mainPg.cid)
                } else {
                player.mplay(mainPg.playUrl)
                contrl.getLyric()}
            }
            onError: {
                console.log("error: "+s);
                gToast.requestToast(s+",请检查网络连接～");
            }
        }

        Connections {
            target: player
            onStateChanged : {
                console.log("status = " + player.mediaStatus)
                if(player.mediaStatus == 7 && mainPg.errorFlag) {
                    mainPg.errorFlag = false
                    console.log("show playUrl = "+ mainPg.playUrl)
                    //                    page.show()
                    contrl.getMusicReq(mainPg.cid)
                }
            }
            onPositionChanged : {
//                console.log("postion = " + player.position)
                lyricListModel.getIndex(player.position);
            }
//            onVolumeChanged: {
//                player.volume = volume;
//            }
        }


        Connections {
            target: lyricListModel
            onCurrentIndexChanged: {
                console.log("currentIndex = "+lyricListModel.currentIndex);
                lyricList.currentIndex = lyricListModel.currentIndex;
                console.log("getIndex="+lyricListModel.getIndex(lyricList.currentIndex))
            }
        }

        Item {
            id: lyric_list
            anchors.fill: parent
            visible: false
            Image {
                id: lyric_background
                source: "qrc:/images/res/background1.jpg"
                anchors.fill: parent
                opacity: 0.2
            }

            Rectangle {
                id: lyric_rec
                color: "#000"
                visible: false
                height: 40
                anchors.top: parent.top
                anchors.topMargin: 80
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: aaa
                    //                    anchors.horizontalCenter: parent.horizontalCenter
                    text: mainPg.title
                    color: "#9c5f5f"
                    font.pixelSize: 40
                }
            }

//            ListView {
//                id: lyricList
//                width: parent.width
//                height: parent.height
//                anchors.horizontalCenter: parent.horizontalCenter
//                anchors.top: lyric_rec.bottom
//                clip: true
//                spacing: 3
//                highlightRangeMode: ListView.StrictlyEnforceRange
//                preferredHighlightBegin: 8
//                preferredHighlightEnd: 30
//                highlightFollowsCurrentItem: true
//                highlight: Rectangle {
//                    color: "#917676"
//                    Behavior on y {
//                        SmoothedAnimation {
//                            duration: 300//???
//                        }
//                    }
//                }
//                model: lyricListModel
//                delegate: Rectangle {
//                    id: lyricRect
//                    width: parent.width
//                    height: 60
//                    color: Qt.rgba(0,0,0,0)
//                    Text {
//                        id: lyricTxt
//                        anchors.centerIn: parent
//                        horizontalAlignment: Text.AlignHCenter
//                        text: textLine
//                        color: "#4c4c4c"
//                        font.pixelSize: 30

//                    }
//                }

//                MouseArea {
//                    anchors.fill: parent
//                    onClicked: {
//                        console.log("double clicked")
//                        mainpage.visible = true;
//                        lyric_list.visible = false
//                    }
//                }
//            }

            ListView {
                id: lyricList
                width: parent.width
                height: parent.height
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: lyric_rec.bottom
                clip: true
                spacing: 3
                highlightRangeMode: ListView.StrictlyEnforceRange
                preferredHighlightBegin: 8
                preferredHighlightEnd: 30
                highlightFollowsCurrentItem: true
                highlight: Item {
//                    color: transparent
                    Behavior on y {
                        SmoothedAnimation {
                            duration: 300//???
                        }
                    }
                }
                model: lyricListModel
                Component {
                    id: delegate
                    Rectangle {
                        id: lyricRect
                        width: parent.width
                        height: 60
                        color: Qt.rgba(0,0,0,0)
                        Text {
                            id: lyricTxt
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            text: textLine
                            font.pixelSize: lyricRect.ListView.isCurrentItem ? 33:30
                            color: lyricRect.ListView.isCurrentItem ?  "#9c5f5f" : "#4c4c4c"
                        }
                    }
                }

                delegate: delegate
                focus: true

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("double clicked")
                        mainpage.visible = true;
                        lyric_list.visible = false
                    }
                }
            }
        }

        Rectangle {
            id: rect
            anchors.top: parent.top
            anchors.topMargin: 40
            width: parent.width
            height: 60
            color: "#000000"

            Image {
                id: list
                source: "qrc:/images/res/expanded.png"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 40
                width: 40
                height: 25
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("channel.visible :"+channel.visible)
                        if(channel.visible) {
                            channel.visible = false
                            mainpage.visible = true
                        } else {
                            channel.visible = true
                            lyric_list.visible = false
                            mainpage.visible = false
                        }
                    }
                }
            }

            Image {
                id: lyric
                source: "qrc:/images/res/ic_music.png"
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 40
                width: 40
                height: 40
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("volume :"+player.volume)
                        if(lyric_list.visible) {
                            lyric_list.visible = false
                            mainpage.visible = true
                        } else {
                            lyric_list.visible = true
                            channel.visible = false
                            mainpage.visible = false
                        }
                    }
                }
            }

            Text {
                color: "#ffffff"
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 35
                font.family: "AR PL UKai CN"
                font.bold: true
                text: "随心听"
            }
        }

//
        Item {
            id: channel
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: rect.bottom
            anchors.bottom: parent.bottom
            visible: false
            Image {
                id: channel_background
                source: "qrc:/images/res/background1.jpg"
                anchors.fill: parent
                opacity: 0.2
            }

            ListView {
                id: view
                //                anchors.left: parent.left
                //                anchors.top: parent.top
                //                width: parent.width/2
                anchors.fill: parent
                model: channelListModel
                clip: true

                delegate: Rectangle {
                    id: _delegate
                    width: view.width
                    height: 80
                    color: Qt.rgba(0,0,0,0)

                    Rectangle {
                        id: decorateLine
                        height: 1
                        color: "#a89292"
                        opacity: 0.2
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
                        color: "#4c4c4c"
                        font.pixelSize:  30
                        elide: Text.ElideRight
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainPg.c_index = index
                            mainPg.cid = channelListModel.getChannel_id(index);
                            console.log("channelId = "+mainPg.cid+",,,index = "+index)
                            mainPg.channelName = titleTxtInfo.text
                            console.log("channel.name ="+ mainPg.channelName)
                            contrl.getMusicReq(mainPg.cid)
                            channel.visible = false
                            mainpage.visible = true
                        }
                    }
                }
            }
        }

        Item {
            id: mainpage
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: rect.bottom
            anchors.bottom: parent.bottom

            Image {
                id: bg
                anchors.fill: parent
                source: mainPg.picture == "" ? "qrc:/images/res/album_init.jpg":mainPg.picture
//                source: "qrc:/images/res/background2.jpg"
                visible: false
//                opacity: player.state == MediaPlayer.PlayingState? 1:0.5
            }

            FastBlur{
                anchors.fill: parent
                source: bg
                radius: 80
            }


            Text {
                id: channel_name
                color: "#5a3939"
                anchors.top: parent.top
                anchors.topMargin: 40
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 45
                font.bold: true
                text:"- -  "+ mainPg.channelName+"  - -"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("clicked")
                        mainpage.visible = false
                        channel.visible = true
                        lyric_list.visible = false
                    }
                }
            }

            RoundImage{
                id: play
                anchors.top: channel_name.bottom
                anchors.topMargin: 40
                anchors.horizontalCenter: parent.horizontalCenter
                //anchors.fill: parent;
                width: 450
                height: 450
                source: mainPg.picture == "" ? "qrc:/images/res/album_init.jpg":mainPg.picture
                color:"lightblue"
                border:5
                opacity: player.state === MediaPlayer.PlayingState? 1:0.5
            }


            Rectangle {
                id: sname
                anchors.top: play.bottom
                anchors.topMargin: 100
                anchors.horizontalCenter: parent.horizontalCenter
                height: 80
                color: transparent

                Marquee {
                    anchors.centerIn: parent
                    width: 300
                    text: mainPg.title
                    textColor: "black"
                    onClicked: {
                        console.log("lyric") ;
                        mainpage.visible = false
                        channel.visible = false
                        lyric_list.visible = true;
                    }
                }
            }

            Text {
                id: song
                color: "#696161"
                anchors.top: sname.bottom
                anchors.topMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 30
                text: mainPg.singer
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
                    id: playorpause
                    width:  80
                    height: 80
                    anchors.verticalCenter: parent.verticalCenter
                    source: player.state === MediaPlayer.PlayingState?"qrc:/images/res/pause_2.png": "qrc:/images/res/play_2.png"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(player.state === MediaPlayer.PlayingState)
                            {
                                console.log("state = "+ player.state)
                                player.pause()
                            } else {
                                console.log("state = "+ player.state)
                                player.play()
                            }
                        }
                    }
                }

                Image {
                    id: next
                    width:  80
                    height: 75
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/res/next_clicked.png"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("next")
                            contrl.getMusicReq(mainPg.cid)
                            //                            mainPg.show()

                            //                            player.mplay(playUrl)
                        }
                    }
                }
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
                                text : "歌名: "+mainPg.title
                                font.pixelSize: 30
                                color: "#625353"
                            }
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 10
                                text : mainPg.singer == "" ? "歌手: "+"未知" : "歌手: "+mainPg.singer
                                font.pixelSize: 30
                                color: "#625353"
                            }
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 10
                                text : mainPg.albumtitle == "" ? "专辑: "+"未知" : "专辑: "+mainPg.albumtitle
                                font.pixelSize: 30
                                color: "#625353"
                            }
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 10
                                text : mainPg.public_time == "" ? "发行时间: "+"未知" : "发行时间: "+mainPg.public_time
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
                height: 15
                color: "#cad5d2"

                Rectangle {
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: player.duration> 0 ? parent.width * player.position / player.duration: 0
                    color: "#699169"
                }
            }
            Rectangle {
                id: showDuration
                anchors.top: progressBar.bottom
                anchors.bottom: parent.bottom
                color: "#000"
                width: parent.width
                Text {
                    anchors.left: parent.left
                    anchors.leftMargin: 30
                    anchors.verticalCenter: parent.verticalCenter
                    text : getTime(player.position)
                    font.pixelSize: 20
                    color: "#fff"
                }

                Text {
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.verticalCenter: parent.verticalCenter
                    text : getTime(player.duration)
                    font.pixelSize: 20
                    color: "#fff"
                }
            }
        }
    }

    function getTime(n) {

        var minute = parseInt(((n/1000).toFixed(0)) / 60);
        //        console.log("minute111 = " + ((n/1000).toFixed(0)) / 60);
        //        console.log("minute = " + minute);
        var second = ((n/1000).toFixed(0)) % 60;
        //        console.log("second = " + second);
        if(minute < 10) {
            minute = "0" + minute;
            //            console.log("minute = " + minute);
        }
        if(second < 10) {
            second = "0" + second;
            //            console.log("second = " + second);
        }
        var m = minute + ":" + second;
        //        console.log("m = " + m);
        return m;
    }

    function show(){
        mainPg.picture = contrl.showMusic(0);
        mainPg.playUrl = contrl.showMusic(1);
        mainPg.title = contrl.showMusic(2);
        mainPg.public_time = contrl.showMusic(3);
        mainPg.singerId = contrl.showMusic(4);
        mainPg.singer = contrl.showMusic(5);
        mainPg.albumtitle = contrl.showMusic(6);
        //            ssid = contrl.showMusic(7);
        //                    like = contrl.showMusic(8);
    }
}

