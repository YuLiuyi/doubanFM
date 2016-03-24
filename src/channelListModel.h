#ifndef CHANNELLISTMODEL_H
#define CHANNELLISTMODEL_H

#include <QUrl>
#include <QDebug>
#include <QAbstractListModel>
#include "channelInfo.h"
#include "controller.h"

class ChannelListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ChannelListModel(QObject *parent = 0);
    ~ChannelListModel() { }

    Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()) const;		//总行数
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;	//用于在qml显示的内容
    Q_INVOKABLE QString getChannel_id(int index) const;
    Q_INVOKABLE QString getName(int index) const;
    Q_INVOKABLE int getSeq_id(int index) const;


    enum Role {
        IDRole = Qt::UserRole + 1,
        nameRole,
        seqIDRole,
    };

private slots:
    void handleList(ChannelList filelist);

signals:


private:

    int mCurrentIndex;
    QString mPath;
    QHash <int, QByteArray> roleNames() const;
    int mIndex;
    ChannelList mChannelList;
};


#endif // CHANNELLISTMODEL_H
