#include "musicplayer.h"

#include <QThread>

MusicPlayer::MusicPlayer(QObject *parent) :
    QObject(parent)
{
    m_mediaPlayer = new MusicPlayer();
    connect(m_mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(handlePositionChanged(qint64)));

    connect(m_mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(handleDurationChanged(qint64)));

    connect(m_mediaPlayer, SIGNAL(mutedChanged(bool)), this, SIGNAL(mutedChanged(bool)));

    connect(m_mediaPlayer, SIGNAL(volumeChanged(int)), this ,SIGNAL(volumeChanged(int)));

    connect(m_mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SIGNAL(stateChanged(QMediaPlayer::State)));

    connect(m_mediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    setVolume(30);

}

void MusicPlayer::setPlaylist(QMediaPlaylist *playlist)
{
    return m_mediaPlayer->setPlaylist(playlist);
}

QMediaContent MusicPlayer::media()
{
    return m_mediaPlayer->media();
}

void MusicPlayer::setMedia(QMediaContent url)
{
    emit m_mediaPlayer->setMedia(url.canonicalUrl());
}

qreal MusicPlayer::playbackRate()
{
    return m_mediaPlayer->playbackRate();
    qDebug()<<__LINE__<<"playbackRate";
}

void MusicPlayer::setPlaybackRate(qreal rate)
{
    emit m_mediaPlayer->setPlaybackRate(rate);
    qDebug()<<__LINE__<<"rate:"<<endl;
}

bool MusicPlayer::muted()
{
    return m_mediaPlayer->muted();
    qDebug()<<"muted!!";
}

void MusicPlayer::setMuted(bool muted)
{
    qDebug()<<Q_FUNC_INFO<<muted;
    m_mediaPlayer->setMuted(muted);
    emit mutedChanged(muted);
}

qint64 MusicPlayer::position()
{
    return m_mediaPlayer->position();
}

qint64 MusicPlayer::duration()
{
    return m_mediaPlayer->duration();
}

int MusicPlayer::volume()
{
    qDebug() << Q_FUNC_INFO;
    return m_mediaPlayer->volume();
}

void MusicPlayer::handlePositionChanged(qint64 position)
{
    emit positionChanged(position);
}

void MusicPlayer::handleStateChanged(QMediaPlayer::State state)
{
    emit stateChanged(state);
}

QMediaPlayer::State MusicPlayer::state()
{
    return m_mediaPlayer->state();
}

QMediaPlayer::MediaStatus MusicPlayer::mediaStatus()
{
    return m_mediaPlayer->mediaStatus();
}

void MusicPlayer::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    emit mediaStatusChanged(status);
}

void MusicPlayer::mplay(QUrl url)
{
    qDebug() << Q_FUNC_INFO << "[thread]  current thread: " << QThread::currentThreadId();

    qDebug()<<__FUNCTION__<<__LINE__<<"play!!!!!!";
    m_mediaPlayer->setMedia(QMediaContent(url));
    play();
}

void MusicPlayer::play()
{
    qDebug() << Q_FUNC_INFO << "[thread]  current thread: " << QThread::currentThreadId();
    qDebug()<<"playing!!!";
    m_mediaPlayer->play();
}

void MusicPlayer::pause()
{
    m_mediaPlayer->pause();
}

void MusicPlayer::stop()
{
    qDebug() <<"stop!!!";
    m_mediaPlayer->stop();
    qDebug()<<"stopped!!!!"<<"duration === "<<duration();
}

void MusicPlayer::setVolume(int volume)
{
    m_mediaPlayer->setVolume(volume);
    qDebug() <<__FUNCTION__<<__LINE__<< "volume = " << volume;
}

