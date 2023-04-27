// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "audiorecorder.h"
#include "ui_audiorecorder.h"
#include <QTimer>
#include <QMediaRecorder>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
#include <audiolevel.h>
#include <qmediadevices.h>
#include <qmediaformat.h>
#include <qaudiodevice.h>
#include <qaudiobuffer.h>
#include <qaudioinput.h>
#include <qimagecapture.h>
#include <QMimeType>
#include <QCloseEvent>
#include <iostream>
#include <QThread>
#include <QMediaFormat>

static QList<qreal> getBufferLevels(const QAudioBuffer &buffer);

AudioRecorder::AudioRecorder(QPushButton *buttonSender, QMainWindow* parentWin, int negLatency)
    : ui(new Ui::AudioRecorder)
{
    ui->setupUi(this);
    trackNumber = buttonSender->property("trackNumber").toInt();
    project = (buttonSender->property("project")).toString();
    m_audioRecorder = new QMediaRecorder(this);
    negativeLatency = negLatency;
    m_captureSession.setRecorder(m_audioRecorder);
    m_captureSession.setAudioInput(new QAudioInput(this));
    m_trackTarget = buttonSender;
    ui->recordButton->setDisabled(true);
    ui->recordButton->setText("Get Ready...");
    connect(m_audioRecorder, &QMediaRecorder::durationChanged, this, &AudioRecorder::updateProgress);
    connect(m_audioRecorder, &QMediaRecorder::recorderStateChanged, this, &AudioRecorder::onStateChanged);
    connect(m_audioRecorder, &QMediaRecorder::errorChanged, this, &AudioRecorder::displayErrorMessage);
    connect(parentWin, SIGNAL(recordingTime()), this, SLOT(receivedStart()));
    connect(parentWin, SIGNAL(initializeRec()), this, SLOT(initialized()));
}

void AudioRecorder::updateProgress(qint64 duration)
{
    if (m_audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
        return;

    ui->statusbar->showMessage(tr("Recorded %1 sec").arg(duration / 1000));
}

void AudioRecorder::onStateChanged(QMediaRecorder::RecorderState state)
{
    QString statusMessage;

    switch (state) {
    case QMediaRecorder::RecordingState:
        statusMessage = tr("Recording to %1").arg(m_audioRecorder->actualLocation().toString());
        ui->recordButton->setText(tr("Stop"));
        ui->pauseButton->setText(tr("Pause"));
        break;
    case QMediaRecorder::PausedState:
        clearAudioLevels();
        statusMessage = tr("Paused");
        ui->recordButton->setText(tr("Stop"));
        ui->pauseButton->setText(tr("Resume"));
        break;
    case QMediaRecorder::StoppedState:
        clearAudioLevels();
        statusMessage = tr("Stopped");
        ui->recordButton->setText(tr("Record"));
        ui->pauseButton->setText(tr("Pause"));
        break;
    }

    ui->pauseButton->setEnabled(m_audioRecorder->recorderState() != QMediaRecorder::StoppedState);
    if (m_audioRecorder->error() == QMediaRecorder::NoError)
        ui->statusbar->showMessage(statusMessage);
}



void AudioRecorder::toggleRecord()
{
   playing = true;
    if (m_audioRecorder->recorderState() == QMediaRecorder::StoppedState) {
        m_captureSession.audioInput()->setDevice(*(new QAudioDevice()));

        QString currentDir = QDir::currentPath(); // Get the absolute path of the current working directory
        QFileInfo currentInfo(currentDir); // Create a QFileInfo object for the current directory
        QString parentDir = currentInfo.dir().path(); // Get the path of the parent directory
        QUrl toRec = QUrl::fromLocalFile(parentDir + "/" + project.mid(3) + "Track " + QString::number(trackNumber + 1) + ".m4a");

        m_audioRecorder->setOutputLocation(toRec);


       QMediaFormat format;
        format.setAudioCodec(QMediaFormat::AudioCodec::AAC);


        m_audioRecorder->setMediaFormat(format);
        m_audioRecorder->setAudioSampleRate(m_captureSession.audioInput()->device().maximumSampleRate());
        m_audioRecorder->setAudioBitRate(96000);
        m_audioRecorder->setAudioChannelCount(1);
        m_audioRecorder->setQuality(QMediaRecorder::HighQuality);
        m_audioRecorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);


        if (clearing == false) {
            QTimer::singleShot(negativeLatency, this, &AudioRecorder::startRecording);
            emit playTime();
        }
        clearing = false;
    }
    else {
        m_audioRecorder->stop();
        playing = false;
    }
}



void AudioRecorder::startRecording() {
    m_audioRecorder->record();
}

void AudioRecorder::togglePause()
{
    if (m_audioRecorder->recorderState() != QMediaRecorder::PausedState)
        m_audioRecorder->pause();
    else
        m_audioRecorder->record();
}

void AudioRecorder::setOutputLocation()
{
#ifdef Q_OS_ANDROID
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Recording"),
                                                 "output."
                                                 + selectedMediaFormat().mimeType().preferredSuffix());
#else
    QString fileName = QFileDialog::getSaveFileName();
#endif
    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));
    m_outputLocationSet = true;
}

void AudioRecorder::displayErrorMessage()
{
    ui->statusbar->showMessage(m_audioRecorder->errorString());
}



void AudioRecorder::clearAudioLevels()
{
    for (auto m_audioLevel : std::as_const(m_audioLevels))
        m_audioLevel->setLevel(0);
}



// returns the audio level for each channel
QList<qreal> getBufferLevels(const QAudioBuffer &buffer)
{
    QList<qreal> values;

    auto format = buffer.format();
    if (!format.isValid())
        return values;

    int channels = buffer.format().channelCount();
    values.fill(0, channels);

    int bytesPerSample = format.bytesPerSample();
    QList<qreal> max_values;
    max_values.fill(0, channels);

    const char *data = buffer.constData<char>();
    for (int i = 0; i < buffer.frameCount(); ++i) {
        for (int j = 0; j < channels; ++j) {
            qreal value = qAbs(format.normalizedSampleValue(data));
            if (value > max_values.at(j))
                max_values[j] = value;
            data += bytesPerSample;
        }
    }

    return max_values;
}

void AudioRecorder::processBuffer(const QAudioBuffer& buffer)
{
    if (m_audioLevels.count() != buffer.format().channelCount()) {
        qDeleteAll(m_audioLevels);
        m_audioLevels.clear();
        for (int i = 0; i < buffer.format().channelCount(); ++i) {
            AudioLevel *level = new AudioLevel(ui->centralwidget);
            m_audioLevels.append(level);
        }
    }

    QList<qreal> levels = getBufferLevels(buffer);
    for (int i = 0; i < levels.count(); ++i)
        m_audioLevels.at(i)->setLevel(levels.at(i));
}

void AudioRecorder::closeEvent(QCloseEvent *event) {
    if(playing){
        toggleRecord();
    }
    QMainWindow::closeEvent(event);
    if(!clearing) {
        emit recordingFinished();
    }
}

void AudioRecorder::receivedStart(){

    ui->recordButton->setDisabled(false);
    toggleRecord();

}
void AudioRecorder::updateFormats(){

}

void AudioRecorder::initialized(){
    clearing = true;
    toggleRecord();
    clearing = true;
    toggleRecord();
    closeEvent(new QCloseEvent());
}