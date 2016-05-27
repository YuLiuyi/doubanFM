/*
  * 本程序使用GPLv2协议发布
  */
#include "lyricmodel.h"

lyricLine::lyricLine() {
    milliseconds = INT_MAX;
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    text = " ";
}

lyricLine::lyricLine(int m, QString t) {
    milliseconds = m;
    text = t;
}

int lyricLine::getmilliseconds() const {
    return milliseconds;
}

QString lyricLine::gettext() const {
    return text;
}

lyricModel::lyricModel(QObject *parent) : QAbstractListModel(parent) {
    m_currentIndex = 0;
}

int lyricModel::currentIndex() const {
    return m_currentIndex;
}

int lyricModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return mLyricData.count();
}

QVariant lyricModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= mLyricData.count())
            return QVariant();
    const lyricLine &ll = mLyricData.at(index.row());
    switch (role) {
    case timeRole:
        return ll.getmilliseconds();
    case textRole:
        return ll.gettext();
        qDebug()<<Q_FUNC_INFO<<__LINE__<<"ll.gettext():"<<ll.gettext();
    default:
        return QVariant();
    }
}

bool lyricModel::setLyric(lyricData lyric) {
        clearData();
    //    qDebug()<<Q_FUNC_INFO<<__LINE__<<"lyric:"<<lyric.at(0).gettext();
        setcurrentIndex(0);
        QString text = lyric.at(0).gettext();
         beginResetModel();
   if(text == "") {
       mLyricData.append(lyricLine(0,"未找到歌词～"));
   } else {
      mLyricData = lyric;
      qDebug()<<Q_FUNC_INFO<<__LINE__<<"lyric:"<<mLyricData.at(0).gettext();
   }
    endResetModel();
    //        return true;
    //    } else {
    //        addSingleLine(lyricLine(0, tr("未找到歌词")));
    //        return false;
    //    }
}

int lyricModel::findIndex(int position) {
    //bug fix
    if (position == 0) {
        setcurrentIndex(0);
        return 0;
    }
    //bug fix end
    int countless = mLyricData.count() - 1, mid = mLyricData.count() / 2, diff = mid / 2;
    while (1) {
        if (mLyricData.at(mid).getmilliseconds() <= position) {
            if (mid < countless && mLyricData.at(mid + 1).getmilliseconds() > position) {
                break;
            } else {
                mid += diff;
            }
        } else {
            mid -= diff;
        }
        diff /= 2;
        if (diff == 0) {
            break;
        }
    }
    setcurrentIndex(mid);
    return mid;
}

int lyricModel::getIndex(int position) {
    if (m_currentIndex + 1 < mLyricData.count() &&
            mLyricData.at(m_currentIndex + 1).getmilliseconds() <= position) {
        m_currentIndex ++;
        emit currentIndexChanged();
    }
    return m_currentIndex;
}

void lyricModel::addSingleLine(lyricLine l) {
    beginInsertRows(QModelIndex(), mLyricData.count(), mLyricData.count());
    mLyricData << l;
    endInsertRows();
}

void lyricModel::removeTopLine() {
    beginRemoveRows(QModelIndex(), 0, 0);
    mLyricData.removeFirst();
    endRemoveRows();
}

void lyricModel::setcurrentIndex(const int & i) {
    if ((i == 0 || (i < mLyricData.count())) && m_currentIndex != i) {
        m_currentIndex = i;
        emit currentIndexChanged();
    }
}

QHash<int, QByteArray> lyricModel::roleNames() const {
    QHash<int, QByteArray> r;
    r[timeRole] = "time";
    r[textRole] = "textLine";
    return r;
}

void lyricModel::clearData() {
    beginResetModel();
    mLyricData.clear();
    endResetModel();
}
