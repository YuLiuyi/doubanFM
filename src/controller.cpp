#include "controller.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#define CHANNEL_REQUEST "https://www.douban.com/j/app/radio/channels"
#define MUSIC_REQUEST "https://www.douban.com/j/app/radio/people?app_name=radio_android&version=100&type=e&channel="

Controller::Controller()
{
    mManager = new QNetworkAccessManager();
    mIsNext = false;
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

    QByteArray getBuf = mChannelInfoReply->readAll();
    qDebug() << Q_FUNC_INFO << "getbuf = " << getBuf;

    proChannelInfo(getBuf);

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

                qDebug() << "======================channels:"<<obj.value("channels");

                QJsonArray jsonArray = obj["channels"].toArray();

                qDebug() << "======================jsonArray:"<<jsonArray.size();

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
                        qDebug() << "======================seq_id:" << obj["seq_id"].toInt();
                        seq_id = obj["seq_id"].toInt();
                        qDebug() << "======================name:" << obj["name"].toString();
                        name = obj["name"].toString();
                        qDebug() << "=====================channel_id:" << obj["channel_id"].toString();
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


void Controller::getMusicReq(QString cid, int sid, bool isNext)
{
    //request url:https://www.douban.com/j/app/radio/people?app_name=radio_android&version=100&type=b&channel=5&sid=4
    mIsNext = isNext;
    QNetworkRequest request;
    QString url = MUSIC_REQUEST;
    qDebug() << Q_FUNC_INFO << "cid = " << cid << "sid = " << sid;
    QString s = QString::number(sid);
    url.append(cid);
    url.append("&");
    url.append("sid=");
    url.append(s);
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

    QByteArray getBuf = mMusicReply->readAll();
    qDebug() << Q_FUNC_INFO << "getbuf = " << getBuf;

    proMusic(mMusicInfoStru, getBuf);

    if(mIsNext) {
        emit freshFinished();
    } else {
        emit getInfoFinished();
    }
    mMusicReply->deleteLater();
}

void Controller::proMusic(struMusicInfo &musicInfo,const QByteArray &buf)
{

    //url:picture, string ssid, playUrl:url, string title, int like(0/1),
    //string public_time, string singers.id, string singers.name,string albumtitle
    QString picture, playUrl, title, public_time, singerId, singer, albumtitle, ssid; int like;

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
                    qDebug() << "======================playUrl:" << obj["url"].toString();
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
    switch (index) {
    case 0:
        qDebug()<<Q_FUNC_INFO;
        return mMusicInfoStru.picture;
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


Controller::~Controller()
{

}
