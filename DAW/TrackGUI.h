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
    QFormLayout* trackHandle = new QFormLayout;
    QGraphicsView* visual = new QGraphicsView;
    QHBoxLayout* track = new QHBoxLayout;
    QString trackName;
    QLabel *label = new QLabel;
    QPushButton* mute = new QPushButton;
    QPushButton* deleteTrack = new QPushButton;
    QSlider* volume = new QSlider;
    int trackNumber = 0;
};

#endif //DAW_TRACKGUI_H
