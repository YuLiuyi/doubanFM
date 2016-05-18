/****************************************************************************
** Meta object code from reading C++ file 'musicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../doubanFM/src/musicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicPlayer_t {
    QByteArrayData data[38];
    char stringdata[457];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlayer_t qt_meta_stringdata_MusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 12),
QT_MOC_LITERAL(4, 42, 19),
QT_MOC_LITERAL(5, 62, 18),
QT_MOC_LITERAL(6, 81, 25),
QT_MOC_LITERAL(7, 107, 13),
QT_MOC_LITERAL(8, 121, 12),
QT_MOC_LITERAL(9, 134, 15),
QT_MOC_LITERAL(10, 150, 14),
QT_MOC_LITERAL(11, 165, 19),
QT_MOC_LITERAL(12, 185, 11),
QT_MOC_LITERAL(13, 197, 13),
QT_MOC_LITERAL(14, 211, 21),
QT_MOC_LITERAL(15, 233, 8),
QT_MOC_LITERAL(16, 242, 18),
QT_MOC_LITERAL(17, 261, 24),
QT_MOC_LITERAL(18, 286, 11),
QT_MOC_LITERAL(19, 298, 15),
QT_MOC_LITERAL(20, 314, 8),
QT_MOC_LITERAL(21, 323, 8),
QT_MOC_LITERAL(22, 332, 12),
QT_MOC_LITERAL(23, 345, 5),
QT_MOC_LITERAL(24, 351, 3),
QT_MOC_LITERAL(25, 355, 5),
QT_MOC_LITERAL(26, 361, 4),
QT_MOC_LITERAL(27, 366, 4),
QT_MOC_LITERAL(28, 371, 5),
QT_MOC_LITERAL(29, 377, 9),
QT_MOC_LITERAL(30, 387, 6),
QT_MOC_LITERAL(31, 394, 8),
QT_MOC_LITERAL(32, 403, 15),
QT_MOC_LITERAL(33, 419, 4),
QT_MOC_LITERAL(34, 424, 8),
QT_MOC_LITERAL(35, 433, 5),
QT_MOC_LITERAL(36, 439, 5),
QT_MOC_LITERAL(37, 445, 11)
    },
    "MusicPlayer\0positionChanged\0\0stateChanged\0"
    "QMediaPlayer::State\0mediaStatusChanged\0"
    "QMediaPlayer::MediaStatus\0volumeChanged\0"
    "mutedChanged\0seekableChanged\0"
    "videoAvailable\0playbackRateChanged\0"
    "mediaChange\0QMediaContent\0"
    "handlePositionChanged\0position\0"
    "handleStateChanged\0handleMediaStatusChanged\0"
    "setPlaylist\0QMediaPlaylist*\0playlist\0"
    "duration\0playbackRate\0mplay\0url\0pause\0"
    "play\0stop\0muted\0setVolume\0volume\0"
    "setMuted\0setPlaybackRate\0rate\0setMedia\0"
    "media\0state\0mediaStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       6,  192, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       3,    1,  137,    2, 0x06 /* Public */,
       5,    1,  140,    2, 0x06 /* Public */,
       7,    1,  143,    2, 0x06 /* Public */,
       8,    1,  146,    2, 0x06 /* Public */,
       9,    1,  149,    2, 0x06 /* Public */,
      11,    1,  152,    2, 0x06 /* Public */,
      12,    1,  155,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  158,    2, 0x0a /* Public */,
      16,    1,  161,    2, 0x0a /* Public */,
      17,    1,  164,    2, 0x0a /* Public */,
      18,    1,  167,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      21,    0,  170,    2, 0x02 /* Public */,
      22,    0,  171,    2, 0x02 /* Public */,
      23,    1,  172,    2, 0x02 /* Public */,
      25,    0,  175,    2, 0x02 /* Public */,
      26,    0,  176,    2, 0x02 /* Public */,
      27,    0,  177,    2, 0x02 /* Public */,
      28,    0,  178,    2, 0x02 /* Public */,
      29,    1,  179,    2, 0x02 /* Public */,
      31,    1,  182,    2, 0x02 /* Public */,
      32,    1,  185,    2, 0x02 /* Public */,
      34,    1,  188,    2, 0x02 /* Public */,
      35,    0,  191,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, 0x80000000 | 13,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,   15,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 19,   20,

 // methods: parameters
    QMetaType::LongLong,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QUrl,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::QReal,   33,
    QMetaType::Void, 0x80000000 | 13,   24,
    0x80000000 | 13,

 // properties: name, type, flags
      21, QMetaType::Int, 0x00095001,
      15, QMetaType::LongLong, 0x00495001,
      36, 0x80000000 | 4, 0x00495009,
      37, 0x80000000 | 6, 0x00495009,
      30, QMetaType::Int, 0x00495103,
      28, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void MusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPlayer *_t = static_cast<MusicPlayer *>(_o);
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 2: _t->mediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 3: _t->volumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->mutedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->seekableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->playbackRateChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->mediaChange((*reinterpret_cast< QMediaContent(*)>(_a[1]))); break;
        case 8: _t->handlePositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->handleStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 10: _t->handleMediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 11: _t->setPlaylist((*reinterpret_cast< QMediaPlaylist*(*)>(_a[1]))); break;
        case 12: { qint64 _r = _t->duration();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 13: { qreal _r = _t->playbackRate();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 14: _t->mplay((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 15: _t->pause(); break;
        case 16: _t->play(); break;
        case 17: _t->stop(); break;
        case 18: { bool _r = _t->muted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->setPlaybackRate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 22: _t->setMedia((*reinterpret_cast< QMediaContent(*)>(_a[1]))); break;
        case 23: { QMediaContent _r = _t->media();
            if (_a[0]) *reinterpret_cast< QMediaContent*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicPlayer::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::positionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(QMediaPlayer::State );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::stateChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(QMediaPlayer::MediaStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::mediaStatusChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::volumeChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::mutedChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::seekableChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::playbackRateChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(QMediaContent );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::mediaChange)) {
                *result = 7;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
        }
    }

}

static const QMetaObject * const qt_meta_extradata_MusicPlayer[] = {
        &QMediaPlayer::staticMetaObject,
    0
};

const QMetaObject MusicPlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MusicPlayer.data,
      qt_meta_data_MusicPlayer,  qt_static_metacall, qt_meta_extradata_MusicPlayer, 0}
};


const QMetaObject *MusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlayer.stringdata))
        return static_cast<void*>(const_cast< MusicPlayer*>(this));
    return QObject::qt_metacast(_clname);
}

int MusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = duration(); break;
        case 1: *reinterpret_cast< qint64*>(_v) = position(); break;
        case 2: *reinterpret_cast< QMediaPlayer::State*>(_v) = state(); break;
        case 3: *reinterpret_cast< QMediaPlayer::MediaStatus*>(_v) = mediaStatus(); break;
        case 4: *reinterpret_cast< int*>(_v) = volume(); break;
        case 5: *reinterpret_cast< bool*>(_v) = muted(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 4: setVolume(*reinterpret_cast< int*>(_v)); break;
        case 5: setMuted(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MusicPlayer::positionChanged(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicPlayer::stateChanged(QMediaPlayer::State _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MusicPlayer::volumeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MusicPlayer::mutedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MusicPlayer::seekableChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MusicPlayer::playbackRateChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MusicPlayer::mediaChange(QMediaContent _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
