// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QMainWindow>
#include <QMediaRecorder>
#include <QMediaCaptureSession>
#include <QUrl>
#include <QDialog>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class AudioRecorder; }
class QAudioBuffer;
QT_END_NAMESPACE

class AudioLevel;

class AudioRecorder : public QMainWindow
{
    Q_OBJECT

public:
    AudioRecorder(QPushButton *buttonSender, QMainWindow* parentWin);
    bool playing = false;
signals:
    void recordingFinished();


public slots:
    void processBuffer(const QAudioBuffer&);

private slots:
    void setOutputLocation();
    void togglePause();
    void toggleRecord();
    void closeEvent(QCloseEvent *event);
    void onStateChanged(QMediaRecorder::RecorderState);
    void updateProgress(qint64 pos);
    void displayErrorMessage();
    void receivedStart();

    void updateFormats();

private:
    void clearAudioLevels();
    QMediaFormat selectedMediaFormat() const;

    Ui::AudioRecorder *ui = nullptr;
    int trackNumber;
    QString project;
    QMediaCaptureSession m_captureSession;
    QMediaRecorder *m_audioRecorder = nullptr;
    QList<AudioLevel*> m_audioLevels;
    bool m_outputLocationSet = false;
    bool m_updatingFormats = false;
    QPushButton* m_trackTarget;

};

#endif // AUDIORECORDER_H