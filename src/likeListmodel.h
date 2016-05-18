//#ifndef LIKELIST_H
//#define LIKELIST_H
//#include <QUrl>
//#include <QDebug>
//#include <QAbstractListModel>

//class LikeList : public QAbstractListModel
//{
//    Q_OBJECT

//public:
//    explicit LikeList(QObject *parent = 0);

//    Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()) const;		//总行数
//    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;	//用于在qml显示的内容
//    Q_INVOKABLE QString getSong(int index) const;
//    Q_INVOKABLE QString getSinger(int index) const;
//    Q_INVOKABLE int getPicUrl(int index) const;


//    enum Role {
//        songRole = Qt::UserRole + 1,
//        singerRole,
//        picUrlRole,
//    };

//private slots:


//signals:


//private:

//    int mCurrentIndex;
//    QString mPath;
//    QHash <int, QByteArray> roleNames() const;
//    int mIndex;
//};


//#endif // LIKELIST_H
