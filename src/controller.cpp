#include "controller.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrlQuery>
#include <QRegExp>
#define CHANNEL_REQUEST "https://www.douban.com/j/app/radio/channels"
#define MUSIC_REQUEST "https://www.douban.com/j/app/radio/people?app_name=radio_android&version=100&type=n&sid=&h=&channel="
#define LYRIC_REQUEST "http://api.douban.com/v2/fm/lyric"

Controller::Controller()
{
    mManager = new QNetworkAccessManager();
}

//send request
void Controller::getChannelInfoReq()
{

    QNetworkRequest request;
    QString url = CHANNEL_REQUEST;
    request.setUrl(QUrl(url));
    qDebug() << Q_FUNC_INFO << "request = ";
    mChannelInfoReply = mManager->get(request);
    connect(mChannelInfoReply, SIGNAL(finished()), this, SLOT(channelInfoReqFinished()));

}

void Controller::channelInfoReqFinished()
{
    int ret = mChannelInfoReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << Q_FUNC_INFO<<"ret===" << ret;

    if(200 == ret) {
        QByteArray getBuf = mChannelInfoReply->readAll();
        qDebug() << Q_FUNC_INFO << "getbuf = " << getBuf;

        proChannelInfo(getBuf);

    } else {
        qDebug() << Q_FUNC_INFO <<__LINE__<<"error";
        emit error("get channel failed!");
    }


    mChannelInfoReply->deleteLater();

}

//
void Controller::proChannelInfo(const QByteArray &buf)
{
    //need string seq_id(0), string name(私人兆赫), string channel_id(0)

    int seq_id;
    QString name, channel_id;

    QJsonParseError jsonError;//Qt5新类
    QJsonDocument json = QJsonDocument::fromJson(buf, &jsonError);

    if(jsonError.error == QJsonParseError::NoError) {
        if(json.isObject())
        {
            QJsonObject obj = json.object();
            if(obj.contains("channels")) {

                //                qDebug() << "======================channels:"<<obj.value("channels");

                QJsonArray jsonArray = obj["channels"].toArray();

                //                qDebug() << "======================jsonArray:"<<jsonArray.size();

                if(jsonArray.size() == 0)
                {
                    qDebug() << "==============size==0======";
                    mChannelList.clear();
                    emit(channelResult(mChannelList));
                }
                else {
                    foreach (const QJsonValue & value, jsonArray)
                    {
                        QJsonObject obj = value.toObject();
                        //                        qDebug() << "======================seq_id:" << obj["seq_id"].toInt();
                        seq_id = obj["seq_id"].toInt();
                        //                        qDebug() << "======================name:" << obj["name"].toString();
                        name = obj["name"].toString();
                        //                        qDebug() << "=====================channel_id:" << obj["channel_id"].toString();
                        channel_id = obj["channel_id"].toString();

                        mChannelList.append(Channel(channel_id, name, seq_id));
                        emit(channelResult(mChannelList));
                    }
                }
            }
        }
    }
}

void Controller::error(QNetworkReply::NetworkError error)
{
    qDebug() << Q_FUNC_INFO << "error=" << error;
}


void Controller::getMusicReq(QString cid)
{
    //request url:https://www.douban.com/j/app/radio/people?app_name=radio_android&version=100&type=n&sid=4&channel=
    QNetworkRequest request;
    QString url = MUSIC_REQUEST;
    qDebug() << Q_FUNC_INFO << "cid = " << cid;
    url.append(cid);
    request.setUrl(QUrl(url));
    qDebug() << Q_FUNC_INFO << "request = "<< request.url().toString();
    mMusicReply = mManager->get(request);
    connect(mMusicReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(mMusicReply, SIGNAL(finished()), this, SLOT(musicReqFinished()));
}

void Controller::musicReqFinished()
{
    int ret = mMusicReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << Q_FUNC_INFO<<"ret===" << ret;

    if(200 == ret) {

        QByteArray getBuf = mMusicReply->readAll();
        qDebug() << Q_FUNC_INFO << "getbuf = " << getBuf;

        proMusic(mMusicInfoStru, getBuf);
        qDebug()<<__LINE__<<"-------------------";
        emit freshFinished();

    } else {
        qDebug() << Q_FUNC_INFO <<__LINE__<<"error";
        error("get music failed!");
    }
    mMusicReply->deleteLater();
}

void Controller::proMusic(struMusicInfo &musicInfo,const QByteArray &buf)
{

    //url:picture, string ssid, playUrl:url, string title, int like(0/1),
    //string public_time, string singers.id, string singers.name,string albumtitle
    QString picture, playUrl, title, public_time, singerId, singer, albumtitle, ssid,songid; int like;

    QJsonParseError jsonError;//Qt5新类
    QJsonDocument json = QJsonDocument::fromJson(buf, &jsonError);

    if(jsonError.error == QJsonParseError::NoError) {
        if(json.isObject())
        {
            QJsonObject obj = json.object();
            if(obj.contains("song")) {

                qDebug() << "======================song:"<<obj.value("song");

                QJsonArray jsonArray = obj["song"].toArray();

                qDebug() << "======================jsonArray:"<<jsonArray.size();

                foreach (const QJsonValue & value, jsonArray)
                {
                    QJsonObject obj = value.toObject();
                    //                    qDebug() << "======================picture:" << obj["picture"].toString();
                    picture = obj["picture"].toString();
                    musicInfo.picture = picture;
                    //                    qDebug() << "======================playUrl:" << obj["url"].toString();
                    playUrl = obj["url"].toString();
                    musicInfo.playUrl = playUrl;
                    //                    qDebug() << "======================title:" << obj["title"].toString();
                    title = obj["title"].toString();
                    musicInfo.title = title;
                    //                    qDebug() << "======================public_time:" << obj["public_time"].toString();
                    public_time = obj["public_time"].toString();
                    musicInfo.public_time = public_time;
                    //                    qDebug() << "======================singerId:" << obj["sid"].toString();
                    singerId = obj["sid"].toString();
                    musicInfo.singerId = singerId;
                    //                    qDebug() << "======================singer:" << obj["artist"].toString();
                    singer = obj["artist"].toString();
                    musicInfo.singer = singer;
                    //                    qDebug() << "======================albumtitle:" << obj["albumtitle"].toString();
                    albumtitle = obj["albumtitle"].toString();
                    musicInfo.albumtitle = albumtitle;
                    //                    qDebug() << "=====================ssid:" << obj["ssid"].toString();
                    ssid = obj["ssid"].toString();
                    musicInfo.ssid = ssid;
                    mSsid = ssid;
                    songid = obj["sid"].toString();
                    mSongid = songid;
                    //                    qDebug() << "=====================like:" << obj["like"].toInt();
                    like = obj["like"].toInt();
                    musicInfo.like = like;
                }
            }
        }
    }
}

QVariant Controller::showMusic(int index)
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<< "showMusic";
    switch (index) {
    case 0:
        return mMusicInfoStru.picture;
        qDebug()<<"pic_url : "<<mMusicInfoStru.picture;
    case 1:
        return mMusicInfoStru.playUrl;
    case 2:
        return mMusicInfoStru.title;
    case 3:
        return mMusicInfoStru.public_time;
    case 4:
        return mMusicInfoStru.singerId;
    case 5:
        return mMusicInfoStru.singer;

        qDebug()<<Q_FUNC_INFO<<mMusicInfoStru.singer;
    case 6:
        return mMusicInfoStru.albumtitle;
    case 7:
        return mMusicInfoStru.ssid;
    case 8:
        return mMusicInfoStru.like;
    default:
        return QVariant();
    }
}

void Controller::getLyric() {

    lrc_map.clear();
    mLyricData.clear();
    qDebug() << "Going to get lyric for " << "sid = "<<mSongid << ",ssid =  " <<mSsid;

    QNetworkRequest request;
    request.setUrl(QUrl(LYRIC_REQUEST));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery postData;
    postData.addQueryItem("sid", mSongid);
    postData.addQueryItem("ssid", mSsid);

    mLyricReply = mManager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    connect(mLyricReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(mLyricReply, SIGNAL(finished()), this, SLOT(lyricReqFinished()));
}
void Controller::lyricReqFinished()
{
    int ret = mLyricReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << Q_FUNC_INFO<<"ret===" << ret;

    if(200 == ret) {

        QByteArray getBuf = mLyricReply->readAll();
        qDebug() << Q_FUNC_INFO << "getbuf = " << getBuf;

        proLyric(getBuf);

    } else {
        qDebug() << Q_FUNC_INFO <<__LINE__<<"error";
        error("get lyric failed!");
    }

    mLyricReply->deleteLater();
}

void Controller::proLyric(const QByteArray &buf)
{

    QJsonParseError jsonError;//Qt5新类
    QJsonDocument json = QJsonDocument::fromJson(buf, &jsonError);

    if(jsonError.error == QJsonParseError::NoError) {
        if(json.isObject())
        {
            QJsonObject obj = json.object();
            if(obj.contains("lyric")) {

                qDebug() << "lyric: "<<obj.value("lyric");
                QString lyric = obj.value("lyric").toString();

                //                QJsonArray jsonArray = obj["channels"].toArray();

                //                qDebug() << "======================jsonArray:"<<jsonArray.size();

                if(lyric == "") {

                    mLyricData.append(lyricLine(0, lyric));

                } else if(lyric == "此曲目为纯音乐") {

                    mLyricData.append(lyricLine(0, lyric));

                } else {

                    QStringList lines = lyric.split("\r\n");

                    //这个是时间标签的格式[00:05.54]
                    //正则表达式d{2}表示匹配2个数字

                    QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
                    int index;
                    for(index = 0; index < lines.length(); index++) {
                        QString oneline = lines.at(index);
//                        qDebug()<<Q_FUNC_INFO<<__LINE__<<"oneline :"<<lines.at(index);
                        QString temp = oneline;
                        temp.replace(rx, "");//用空字符串替换正则表达式中所匹配的地方,这样就获得了歌词文本
                        // 然后依次获取当前行中的所有时间标签，并分别与歌词文本存入QMap中
                        //indexIn()为返回第一个匹配的位置，如果返回为-1，则表示没有匹配成功
                        //正常情况下pos后面应该对应的是歌词文件
                        int pos = rx.indexIn(oneline, 0);
                        while (pos != -1) { //表示匹配成功
                            QString cap = rx.cap(0);//返回第0个表达式匹配的内容
                            // 将时间标签转换为时间数值，以毫秒为单位
                            QRegExp regexp;
                            regexp.setPattern("\\d{2}(?=:)");
                            regexp.indexIn(cap);
                            int minute = regexp.cap(0).toInt();
                            regexp.setPattern("\\d{2}(?=\\.)");
                            regexp.indexIn(cap);
                            int second = regexp.cap(0).toInt();
                            regexp.setPattern("\\d{2}(?=\\])");
                            regexp.indexIn(cap);
                            int millisecond = regexp.cap(0).toInt();
                            qint64 totalTime = minute * 60000 + second * 1000 + millisecond * 10;
                            qDebug()<<__LINE__<<"totalTime = "<<totalTime;

                            lrc_map.insert(totalTime, temp);

                            pos += rx.matchedLength();
                            pos = rx.indexIn(oneline, pos);//匹配全部
                            qDebug()<<__LINE__<<"pos = "<<pos;

                        }
                    }
                    QMap<qint64, QString>::iterator it; //遍历map
                    for ( it = lrc_map.begin(); it != lrc_map.end(); ++it ){
                        if(it.key() == 0) {
                            qDebug()<<Q_FUNC_INFO<<__LINE__;
                            mLyricData.append(lyricLine(0,it.value()));
                        } else {
                            qDebug()<<Q_FUNC_INFO<<__LINE__;
                            mLyricData.append(lyricLine(it.key(), it.value()));
                        }
                    }
                }

                emit proLyricFinished(mLyricData);
            }
        }
    }
}

//void Controller::UpdateTime(qint64 time)
//{
//    qint64 total_time_value = MusicPlayer::duration();//直接获取该音频文件的总时长参数，单位为毫秒
//    //这3个参数分别代表了时，分，秒；60000毫秒为1分钟，所以分钟第二个参数是先除6000,第3个参数是直接除1s
//    QTime total_time(0, (total_time_value/60000)%60, (total_time_value/1000)%60);
//    QTime current_time(0, (time/60000)%60, (time/1000)%60);//传进来的time参数代表了当前的时间
//    QString str = current_time.toString("mm:ss") + "/" + total_time.toString("mm:ss");
//    time_label->setText(str);

//    // 获取当期时间对应的歌词
//    if(!lrc_map.isEmpty()) {
//        // 获取当前时间在歌词中的前后两个时间点
//        qint64 previous = 0;
//        qint64 later = 0;
//        int index;
//        //keys()方法返回lrc_map列表
//        for (index = 0; index < lrc_map.length(); index ++) {
//            int value = lrc_map.at(i).getmilliseconds();
//            if (time >= value) {
//                previous = value;
//            } else {
//                later = value;
//                break;
//            }
//        }

//        // 达到最后一行,将later设置为歌曲总时间的值
//        if (later == 0)
//            later = total_time_value;

//        // 获取当前时间所对应的歌词内容
//        QString current_lrc = lrc_map.value(previous);

////        // 没有内容时
////        if(current_lrc.length() < 2)
////            current_lrc = tr("简易音乐播放器");

//        // 如果是新的一行歌词，那么重新开始显示歌词遮罩
//        if(current_lrc != lrc->text()) {
//            lrc->setText(current_lrc);
//            top_label->setText(current_lrc);
//            qint64 interval_time = later - previous;
//            lrc->start_lrc_mask(interval_time);
//        }
//    } else {  // 如果没有歌词文件，则在顶部标签中显示歌曲标题
//        qDebug()<< "没有歌词文件";
//    }
//}

//QString Controller::showLyric(){

//    qDebug()<< "lyric: " << mLyric;
//    mLyric.remove(QRegularExpression("[\]\[0-9:\.]"));
//    return mLyric;
//}


Controller::~Controller()
{

}
