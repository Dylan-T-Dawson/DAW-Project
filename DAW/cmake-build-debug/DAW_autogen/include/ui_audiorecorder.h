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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioRecorder
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *audioDeviceBox;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QComboBox *containerBox;
    QComboBox *audioCodecBox;
    QLabel *label_5;
    QComboBox *channelsBox;
    QSpinBox *sampleRateBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *constantQualityRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QSlider *qualitySlider;
    QRadioButton *constantBitrateRadioButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *bitrateBox;
    QPushButton *outputButton;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QLabel *levelLabel;
    QVBoxLayout *levelsLayout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AudioRecorder)
    {
        if (AudioRecorder->objectName().isEmpty())
            AudioRecorder->setObjectName("AudioRecorder");
        AudioRecorder->resize(297, 476);
        centralwidget = new QWidget(AudioRecorder);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        audioDeviceBox = new QComboBox(centralwidget);
        audioDeviceBox->setObjectName("audioDeviceBox");

        gridLayout_2->addWidget(audioDeviceBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        containerBox = new QComboBox(centralwidget);
        containerBox->setObjectName("containerBox");

        gridLayout_2->addWidget(containerBox, 2, 1, 1, 1);

        audioCodecBox = new QComboBox(centralwidget);
        audioCodecBox->setObjectName("audioCodecBox");

        gridLayout_2->addWidget(audioCodecBox, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        channelsBox = new QComboBox(centralwidget);
        channelsBox->setObjectName("channelsBox");

        gridLayout_2->addWidget(channelsBox, 4, 1, 1, 1);

        sampleRateBox = new QSpinBox(centralwidget);
        sampleRateBox->setObjectName("sampleRateBox");

        gridLayout_2->addWidget(sampleRateBox, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        constantQualityRadioButton = new QRadioButton(groupBox);
        constantQualityRadioButton->setObjectName("constantQualityRadioButton");
        constantQualityRadioButton->setChecked(true);

        gridLayout->addWidget(constantQualityRadioButton, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        qualitySlider = new QSlider(groupBox);
        qualitySlider->setObjectName("qualitySlider");
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(qualitySlider, 1, 1, 1, 1);

        constantBitrateRadioButton = new QRadioButton(groupBox);
        constantBitrateRadioButton->setObjectName("constantBitrateRadioButton");

        gridLayout->addWidget(constantBitrateRadioButton, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        bitrateBox = new QComboBox(groupBox);
        bitrateBox->setObjectName("bitrateBox");
        bitrateBox->setEnabled(false);

        gridLayout->addWidget(bitrateBox, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 3);

        outputButton = new QPushButton(centralwidget);
        outputButton->setObjectName("outputButton");

        gridLayout_3->addWidget(outputButton, 2, 0, 1, 1);

        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName("recordButton");

        gridLayout_3->addWidget(recordButton, 2, 1, 1, 1);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setEnabled(false);

        gridLayout_3->addWidget(pauseButton, 2, 2, 1, 1);

        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName("levelLabel");

        gridLayout_3->addWidget(levelLabel, 3, 0, 1, 1);

        levelsLayout = new QVBoxLayout();
        levelsLayout->setObjectName("levelsLayout");

        gridLayout_3->addLayout(levelsLayout, 3, 1, 1, 2);

        AudioRecorder->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AudioRecorder);
        statusbar->setObjectName("statusbar");
        AudioRecorder->setStatusBar(statusbar);

        retranslateUi(AudioRecorder);
        QObject::connect(constantQualityRadioButton, &QRadioButton::toggled, qualitySlider, &QSlider::setEnabled);
        QObject::connect(constantBitrateRadioButton, &QRadioButton::toggled, bitrateBox, &QComboBox::setEnabled);
        QObject::connect(outputButton, SIGNAL(clicked()), AudioRecorder, SLOT(setOutputLocation()));
        QObject::connect(recordButton, SIGNAL(clicked()), AudioRecorder, SLOT(toggleRecord()));
        QObject::connect(pauseButton, SIGNAL(clicked()), AudioRecorder, SLOT(togglePause()));

        QMetaObject::connectSlotsByName(AudioRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *AudioRecorder)
    {
        AudioRecorder->setWindowTitle(QCoreApplication::translate("AudioRecorder", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("AudioRecorder", "Sample rate:", nullptr));
        label_2->setText(QCoreApplication::translate("AudioRecorder", "Audio Codec:", nullptr));
        label->setText(QCoreApplication::translate("AudioRecorder", "Input Device:", nullptr));
        label_3->setText(QCoreApplication::translate("AudioRecorder", "File Container:", nullptr));
        label_5->setText(QCoreApplication::translate("AudioRecorder", "Channels:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AudioRecorder", "Encoding Mode:", nullptr));
        constantQualityRadioButton->setText(QCoreApplication::translate("AudioRecorder", "Constant Quality:", nullptr));
        constantBitrateRadioButton->setText(QCoreApplication::translate("AudioRecorder", "Constant Bitrate:", nullptr));
        outputButton->setText(QCoreApplication::translate("AudioRecorder", "Output...", nullptr));
        recordButton->setText(QCoreApplication::translate("AudioRecorder", "Record", nullptr));
        pauseButton->setText(QCoreApplication::translate("AudioRecorder", "Pause", nullptr));
        levelLabel->setText(QCoreApplication::translate("AudioRecorder", "Audio Level:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioRecorder: public Ui_AudioRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H