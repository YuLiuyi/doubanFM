#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QObject>

class MusicPlayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int duration READ duration)
    Q_PROPERTY(qint64 position READ position NOTIFY positionChanged)
    Q_PROPERTY(QMediaPlayer::State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QMediaPlayer::MediaStatus mediaStatus READ mediaStatus NOTIFY mediaStatusChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(bool muted READ muted WRITE setMuted NOTIFY mutedChanged)


public:

    explicit MusicPlayer(QObject *parent = 0);

    Q_INVOKABLE qint64 duration();                  //音视频的长度
    qint64 position();                  //播放的位置
    int volume();                       //音量
    Q_INVOKABLE qreal playbackRate();   //播放速率
    Q_INVOKABLE void mplay(QUrl url);   //url为播放文件的路径
    Q_INVOKABLE void pause();           //暂停
    Q_INVOKABLE void play();            //播放
    Q_INVOKABLE void stop();        	//停止
    Q_INVOKABLE bool muted();           //是否静音
    Q_INVOKABLE void setVolume(int volume);//设置音量
    Q_INVOKABLE void setMuted(bool muted); //设置为静音
    Q_INVOKABLE void setPlaybackRate(qreal rate);//设置播放速率

    Q_INVOKABLE void setMedia(QMediaContent url);//
    Q_INVOKABLE QMediaContent media();      //

    QMediaPlayer::State state();            //播放状态
    QMediaPlayer::MediaStatus mediaStatus();	//媒体当前状态


signals:
    void positionChanged(qint64);
    void stateChanged(QMediaPlayer::State);
    void mediaStatusChanged(QMediaPlayer::MediaStatus);
    void volumeChanged(int);
    void mutedChanged(bool);
    void seekableChanged(bool videoAvailable);
    void playbackRateChanged(float);
    void mediaChange(QMediaContent);

public slots:
    void handlePositionChanged(qint64 position);
    void handleStateChanged(QMediaPlayer::State);
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus);
    void setPlaylist(QMediaPlaylist *playlist);

private:
    MusicPlayer *m_mediaPlayer;
};

#endif // MUSICPLAYER_H
