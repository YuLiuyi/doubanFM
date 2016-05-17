#include "channelListModel.h"
#include <QFileInfo>
#include <QDir>

ChannelListModel::ChannelListModel(QObject *parent) : QAbstractListModel(parent)
{
    qDebug() <<__FUNCTION__<<__LINE__<< "list 1111111111111111";
    mIndex = 0;
    mCurrentIndex = -1;             //设初值
}

int ChannelListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    qDebug()<<"=======mChannelList.count()======"<<mChannelList.count();
    return mChannelList.count();
}

void ChannelListModel::handleList(ChannelList filelist)
{
    beginResetModel();
    mChannelList = filelist;
    endResetModel();
}

QVariant ChannelListModel::data(const QModelIndex & index, int role) const
{
    qDebug()<<"=======data======";
    if (index.row() < 0 || index.row() >= mChannelList.count())//是否越界
        return QVariant();
    const Channel c = mChannelList.at(index.row());
    switch (role) {
    case IDRole:
        return c.getChannel_id();
    case nameRole:
        return c.getName();
    case seqIDRole:
        return c.getSeq_id();
    default:
        return QVariant();
    }
}

QString ChannelListModel::getChannel_id(int index) const
{
    qDebug() << Q_FUNC_INFO << "====getChannel_id===row====" << index;
    QString id;
    if (index >= 0 && index < mChannelList.size()) {
        id = mChannelList.at(index).getChannel_id();
    }
    qDebug() << Q_FUNC_INFO << "====getChannel_id=======" << id;
    return id;

}

int ChannelListModel::getSeq_id(int index) const
{
    qDebug() << Q_FUNC_INFO << "====getSeq_id===row====" << index;
    int id;
    if (index >= 0 && index < mChannelList.size()) {
        id = mChannelList.at(index).getSeq_id();
    }
    qDebug() << Q_FUNC_INFO << "====getSeq_id=======" << id;
    return id;

}

QString ChannelListModel::getName(int index) const
{
    qDebug() << Q_FUNC_INFO << "====getName===row====" << index;
    QString str;
    if (index >= 0 && index < mChannelList.size()) {
        str = mChannelList.at(index).getName();
    }
    qDebug() << Q_FUNC_INFO << "====getName=======" << str;
    return str;

}

QHash<int, QByteArray> ChannelListModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO;
    QHash<int, QByteArray> role;
    role[nameRole] = "name";
    role[IDRole] = "channel_id";
    role[seqIDRole] = "seq_id";
    return role;
}
