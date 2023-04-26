/****************************************************************************
** Meta object code from reading C++ file 'audiorecorder.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../audiorecorder.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiorecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_AudioRecorder_t {
    uint offsetsAndSizes[36];
    char stringdata0[14];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[18];
    char stringdata6[12];
    char stringdata7[13];
    char stringdata8[11];
    char stringdata9[13];
    char stringdata10[6];
    char stringdata11[15];
    char stringdata12[30];
    char stringdata13[15];
    char stringdata14[4];
    char stringdata15[20];
    char stringdata16[14];
    char stringdata17[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AudioRecorder_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AudioRecorder_t qt_meta_stringdata_AudioRecorder = {
    {
        QT_MOC_LITERAL(0, 13),  // "AudioRecorder"
        QT_MOC_LITERAL(14, 17),  // "recordingFinished"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 13),  // "processBuffer"
        QT_MOC_LITERAL(47, 12),  // "QAudioBuffer"
        QT_MOC_LITERAL(60, 17),  // "setOutputLocation"
        QT_MOC_LITERAL(78, 11),  // "togglePause"
        QT_MOC_LITERAL(90, 12),  // "toggleRecord"
        QT_MOC_LITERAL(103, 10),  // "closeEvent"
        QT_MOC_LITERAL(114, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(127, 5),  // "event"
        QT_MOC_LITERAL(133, 14),  // "onStateChanged"
        QT_MOC_LITERAL(148, 29),  // "QMediaRecorder::RecorderState"
        QT_MOC_LITERAL(178, 14),  // "updateProgress"
        QT_MOC_LITERAL(193, 3),  // "pos"
        QT_MOC_LITERAL(197, 19),  // "displayErrorMessage"
        QT_MOC_LITERAL(217, 13),  // "receivedStart"
        QT_MOC_LITERAL(231, 13)   // "updateFormats"
    },
    "AudioRecorder",
    "recordingFinished",
    "",
    "processBuffer",
    "QAudioBuffer",
    "setOutputLocation",
    "togglePause",
    "toggleRecord",
    "closeEvent",
    "QCloseEvent*",
    "event",
    "onStateChanged",
    "QMediaRecorder::RecorderState",
    "updateProgress",
    "pos",
    "displayErrorMessage",
    "receivedStart",
    "updateFormats"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AudioRecorder[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   81,    2, 0x0a,    2 /* Public */,
       5,    0,   84,    2, 0x08,    4 /* Private */,
       6,    0,   85,    2, 0x08,    5 /* Private */,
       7,    0,   86,    2, 0x08,    6 /* Private */,
       8,    1,   87,    2, 0x08,    7 /* Private */,
      11,    1,   90,    2, 0x08,    9 /* Private */,
      13,    1,   93,    2, 0x08,   11 /* Private */,
      15,    0,   96,    2, 0x08,   13 /* Private */,
      16,    0,   97,    2, 0x08,   14 /* Private */,
      17,    0,   98,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AudioRecorder::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_AudioRecorder.offsetsAndSizes,
    qt_meta_data_AudioRecorder,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AudioRecorder_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AudioRecorder, std::true_type>,
        // method 'recordingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processBuffer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QAudioBuffer &, std::false_type>,
        // method 'setOutputLocation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'togglePause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleRecord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>,
        // method 'onStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaRecorder::RecorderState, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'displayErrorMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receivedStart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFormats'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AudioRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioRecorder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recordingFinished(); break;
        case 1: _t->processBuffer((*reinterpret_cast< std::add_pointer_t<QAudioBuffer>>(_a[1]))); break;
        case 2: _t->setOutputLocation(); break;
        case 3: _t->togglePause(); break;
        case 4: _t->toggleRecord(); break;
        case 5: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 6: _t->onStateChanged((*reinterpret_cast< std::add_pointer_t<QMediaRecorder::RecorderState>>(_a[1]))); break;
        case 7: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->displayErrorMessage(); break;
        case 9: _t->receivedStart(); break;
        case 10: _t->updateFormats(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioRecorder::*)();
            if (_t _q_method = &AudioRecorder::recordingFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *AudioRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioRecorder.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AudioRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AudioRecorder::recordingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
