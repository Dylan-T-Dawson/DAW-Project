#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProcess>
#include <QApplication>
#include <QStyle>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

#include "jack/jack.h"
#include <jack/systemdeps.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <string>

#include "TrackFIle.h"
#include "TrackGUI.h"
#include "QLRClickButton.h"
#include "audiorecorder.h"

#define maxTrack 8

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);


    ~MainWindow() override;

signals:
    void recordingTime();

private slots:

    void addTrack();
    void removeTrack();
    void recordTrack();
    void playTrack();
    void sync();
    void loadProject();
    void deleteProject();
    void addProject();
    void Reload();
    void playAll();
    void onRecordingFinished();
    static void quit();

private:
    Ui::MainWindow* ui;

    int numTracks; //Number of tracks in current project
    bool loaded = false; //True if any project has been loaded in the current session


    std::string fullProjectPath; //Full path to the current project.
    std::string currentProject; //Relative path to the current project.

    std::vector<TrackGUI*> tracks; //Holds instances of the TrackGUI class to represent tracks
    std::vector<TrackFile*> trackFiles; //Holds instances of the trackFile class to represent files tied to tracks

    QProcess* jackProcess; //Audio playback or record processes will look like this.

};

#endif // MAINWINDOW_H