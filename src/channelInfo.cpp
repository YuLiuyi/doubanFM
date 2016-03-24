#include "channelInfo.h"

Channel::Channel()
{

}

Channel::Channel(QString channel_id, QString name, int seq_id)
{
    mSeq_id = seq_id;
    mName = name;
    mChannel_id = channel_id;
}

QString Channel::getChannel_id() const
{
    return mChannel_id;
}

int Channel::getSeq_id()const
{
    return mSeq_id;
}

QString Channel::getName()const
{
    return mName;
}
