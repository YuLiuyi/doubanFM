#include "douban_Workspace.h"
#include <QDebug>
#include "channelInfo.h"
#include <QQmlContext>


douban_Workspace::douban_Workspace()
    : CWorkspace()
{
    qRegisterMetaType<ChannelList>("ChannelList");
    qRegisterMetaType<lyricData>("lyricData");

    m_view = SYBEROS::SyberosGuiCache::qQuickView();
    QObject::connect(m_view->engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    mLyricModel = new lyricModel;
    m_view->rootContext()->setContextProperty("lyricListModel", mLyricModel);

    mChannelListModel = new ChannelListModel;
    m_view->rootContext()->setContextProperty("channelListModel", mChannelListModel);

    m_view->rootContext()->setContextProperty("contrl", &contrl);
    QObject::connect(&contrl,SIGNAL(channelResult(ChannelList)), mChannelListModel, SLOT(handleList(ChannelList)));
    QObject::connect(&contrl,SIGNAL(proLyricFinished(lyricData)), mLyricModel, SLOT(setLyric(lyricData)));

    mMediaPlayer = new MusicPlayer;
    m_view->rootContext()->setContextProperty("player", mMediaPlayer);
//    qmlRegisterType<MusicPlayer>("MusicPlayer", 1, 0, "MusicPlayer");
    qmlRegisterType<lyricModel>("dataModel", 1, 0, "LyricModel");

    m_view->setSource(QUrl("qrc:/qml/main.qml"));
    m_view->showFullScreen();
}

void douban_Workspace::onLaunchComplete(Option option, const QStringList& params)
{
    Q_UNUSED(params)

    switch (option) {
    case CWorkspace::HOME:
        qDebug()<< "Start by Home";
        break;
    case CWorkspace::URL:
        break;
    case CWorkspace::EVENT:
        break;
    case CWorkspace::DOCUMENT:
        break;
    default:
        break;
    }
}


