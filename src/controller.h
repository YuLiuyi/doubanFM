#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMap>
#include "channelInfo.h"
#include "musicplayer.h"
#include "lyricmodel.h"

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

    //lyric
    Q_INVOKABLE void getLyric();
    void proLyric(const QByteArray &buf);
//    Q_INVOKABLE QString showLyric();
    void UpdateTime(qint64 time);

signals:
    void channelResult(ChannelList list);
    void getInfoFinished();
    void freshFinished();
    void proLyricFinished(lyricData);
    void lyricNull();
    void error(QString s);

private slots:
    //channel
    void channelInfoReqFinished();
    //music
    void musicReqFinished();

    //lyric
    void lyricReqFinished();

    void error(QNetworkReply::NetworkError error);

private:
    ChannelList            mChannelList;
    QNetworkAccessManager  *mManager;
    QNetworkReply          *mChannelInfoReply;
    QNetworkReply          *mMusicReply;
    struMusicInfo          mMusicInfoStru;
    bool                   mIsNext;
    QNetworkReply          *mLyricReply;
    QString                mSongid;
    QString                mSsid;
    QString                mLyric;
    lyricData              mLyricData;
    QMap<qint64, QString>  lrc_map;

};


#endif // CONTROLLER_H
