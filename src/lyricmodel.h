/*
  * 本程序使用GPLv2协议发布
  */
#ifndef LYRICMODEL_H
#define LYRICMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

class lyricLine {
public:
    explicit lyricLine();
    explicit lyricLine(int m,QString t);
    int getmilliseconds() const;
    QString gettext() const;

private:
    int milliseconds;
    QString text;
};

typedef QList<lyricLine> lyricData, tempData;

class lyricModel : public QAbstractListModel {
    Q_OBJECT
public:

    Q_PROPERTY(int currentIndex READ currentIndex WRITE setcurrentIndex NOTIFY currentIndexChanged)

    explicit lyricModel(QObject *parent = 0);
    int currentIndex() const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE int findIndex(int position);
    Q_INVOKABLE int getIndex(int position);

    void addSingleLine(lyricLine l);
    void removeTopLine();
    void setcurrentIndex(const int & i);

    enum lyricRoles {
        timeRole = Qt::UserRole + 1,
        textRole,
    };

signals:
    void currentIndexChanged();

public slots:
    bool setLyric(lyricData lyric);

private:
    QHash<int, QByteArray> roleNames() const;
    void clearData();
    lyricData mLyricData;

    int m_currentIndex;
};

#endif // LYRICMODEL_H
