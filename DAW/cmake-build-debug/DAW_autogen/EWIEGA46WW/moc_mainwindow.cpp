/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[38];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[9];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[10];
    char stringdata8[5];
    char stringdata9[12];
    char stringdata10[14];
    char stringdata11[11];
    char stringdata12[7];
    char stringdata13[8];
    char stringdata14[12];
    char stringdata15[8];
    char stringdata16[10];
    char stringdata17[20];
    char stringdata18[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "recordingTime"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 13),  // "initializeRec"
        QT_MOC_LITERAL(40, 8),  // "addTrack"
        QT_MOC_LITERAL(49, 11),  // "removeTrack"
        QT_MOC_LITERAL(61, 11),  // "recordTrack"
        QT_MOC_LITERAL(73, 9),  // "playTrack"
        QT_MOC_LITERAL(83, 4),  // "sync"
        QT_MOC_LITERAL(88, 11),  // "loadProject"
        QT_MOC_LITERAL(100, 13),  // "deleteProject"
        QT_MOC_LITERAL(114, 10),  // "addProject"
        QT_MOC_LITERAL(125, 6),  // "Reload"
        QT_MOC_LITERAL(132, 7),  // "playAll"
        QT_MOC_LITERAL(140, 11),  // "sliderEvent"
        QT_MOC_LITERAL(152, 7),  // "stopAll"
        QT_MOC_LITERAL(160, 9),  // "muteTrack"
        QT_MOC_LITERAL(170, 19),  // "onRecordingFinished"
        QT_MOC_LITERAL(190, 4)   // "quit"
    },
    "MainWindow",
    "recordingTime",
    "",
    "initializeRec",
    "addTrack",
    "removeTrack",
    "recordTrack",
    "playTrack",
    "sync",
    "loadProject",
    "deleteProject",
    "addProject",
    "Reload",
    "playAll",
    "sliderEvent",
    "stopAll",
    "muteTrack",
    "onRecordingFinished",
    "quit"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,    1 /* Public */,
       3,    0,  117,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    0,  121,    2, 0x08,    6 /* Private */,
       8,    0,  122,    2, 0x08,    7 /* Private */,
       9,    0,  123,    2, 0x08,    8 /* Private */,
      10,    0,  124,    2, 0x08,    9 /* Private */,
      11,    0,  125,    2, 0x08,   10 /* Private */,
      12,    0,  126,    2, 0x08,   11 /* Private */,
      13,    0,  127,    2, 0x08,   12 /* Private */,
      14,    0,  128,    2, 0x08,   13 /* Private */,
      15,    0,  129,    2, 0x08,   14 /* Private */,
      16,    0,  130,    2, 0x08,   15 /* Private */,
      17,    0,  131,    2, 0x08,   16 /* Private */,
      18,    0,  132,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'recordingTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initializeRec'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recordTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sync'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sliderEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'muteTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRecordingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recordingTime(); break;
        case 1: _t->initializeRec(); break;
        case 2: _t->addTrack(); break;
        case 3: _t->removeTrack(); break;
        case 4: _t->recordTrack(); break;
        case 5: _t->playTrack(); break;
        case 6: _t->sync(); break;
        case 7: _t->loadProject(); break;
        case 8: _t->deleteProject(); break;
        case 9: _t->addProject(); break;
        case 10: _t->Reload(); break;
        case 11: _t->playAll(); break;
        case 12: _t->sliderEvent(); break;
        case 13: _t->stopAll(); break;
        case 14: _t->muteTrack(); break;
        case 15: _t->onRecordingFinished(); break;
        case 16: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::recordingTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::initializeRec; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::recordingTime()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::initializeRec()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
