#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "channelInfo.h"

typedef struct _musicInfoJson
{
    QString picture;
    QString playUrl;
    QString title;
    QString public_time;
    QString singerId;
    QString singer;
    QString albumtitle;
    QString ssid;
    int like;
}struMusicInfo;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller();
    ~Controller();

    //channel
    Q_INVOKABLE void getChannelInfoReq();
    void proChannelInfo(const QByteArray &buf);

    //music
    Q_INVOKABLE void getMusicReq(QString cid, int sid, bool isNext);
    void proMusic(struMusicInfo &musicInfo,const QByteArray &buf);
    Q_INVOKABLE QVariant showMusic(int index);


signals:
    void channelResult(ChannelList list);
    void getInfoFinished();
    void freshFinished();

private slots:
    //channel
    void channelInfoReqFinished();
    //music
    void musicReqFinished();

    void error(QNetworkReply::NetworkError error);

private:
    ChannelList            mChannelList;
    QNetworkAccessManager  *mManager;
    QNetworkReply          *mChannelInfoReply;
    QNetworkReply          *mMusicReply;
    struMusicInfo          mMusicInfoStru;
    bool                   mIsNext;

};


#endif // CONTROLLER_H
