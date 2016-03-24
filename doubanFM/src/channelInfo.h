#ifndef CHANNELINFO_H
#define CHANNELINFO_H
#include <QObject>
#include <QList>

class Channel
{

public:
    Channel();
    explicit Channel(QString channel_id, QString name, int seq_id);
    int getSeq_id() const;
    QString getName() const;
    QString getChannel_id() const;


private:
    QString mName;
    int mSeq_id;
    QString mChannel_id;
};

typedef QList <Channel> ChannelList;

#endif // CHANNELINFO_H
