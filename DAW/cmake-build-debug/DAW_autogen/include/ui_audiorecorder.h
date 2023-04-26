/********************************************************************************
** Form generated from reading UI file 'audiorecorder.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIORECORDER_H
#define UI_AUDIORECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioRecorder
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AudioRecorder)
    {
        if (AudioRecorder->objectName().isEmpty())
            AudioRecorder->setObjectName("AudioRecorder");
        AudioRecorder->resize(215, 76);
        centralwidget = new QWidget(AudioRecorder);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName("recordButton");

        gridLayout_3->addWidget(recordButton, 0, 0, 1, 1);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setEnabled(false);

        gridLayout_3->addWidget(pauseButton, 0, 1, 1, 1);

        AudioRecorder->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AudioRecorder);
        statusbar->setObjectName("statusbar");
        AudioRecorder->setStatusBar(statusbar);

        retranslateUi(AudioRecorder);
        QObject::connect(recordButton, SIGNAL(clicked()), AudioRecorder, SLOT(toggleRecord()));
        QObject::connect(pauseButton, SIGNAL(clicked()), AudioRecorder, SLOT(togglePause()));

        QMetaObject::connectSlotsByName(AudioRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *AudioRecorder)
    {
        AudioRecorder->setWindowTitle(QCoreApplication::translate("AudioRecorder", "MainWindow", nullptr));
        recordButton->setText(QCoreApplication::translate("AudioRecorder", "Record", nullptr));
        pauseButton->setText(QCoreApplication::translate("AudioRecorder", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioRecorder: public Ui_AudioRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H
