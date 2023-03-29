//
// Created by dtda230 on 3/22/2023.
//

#ifndef DAW_TRACKGUI_H
#define DAW_TRACKGUI_H
#include <QObject>
#include <QApplication>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

class TrackGUI {
public:

    explicit TrackGUI(QString name, int trackNum);

    //Graphics
    QFormLayout* trackHandle = new QFormLayout;
    QGraphicsView* visual = new QGraphicsView;
    QHBoxLayout* track = new QHBoxLayout;
    QLabel *label = new QLabel;
    QPushButton* mute = new QPushButton;
    QPushButton* deleteTrack = new QPushButton;
    QSlider* volume = new QSlider;
    QHBoxLayout* muteLayout;
    QHBoxLayout* volumeLayout;

    QString trackName; //Name of track
    std::string audioFileName; //Name of file associated with track.
    int trackNumber = 0; //Position in current project.

    ~TrackGUI();
};

#endif //DAW_TRACKGUI_H
