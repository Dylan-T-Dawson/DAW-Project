
#include <algorithm>
#include <QApplication>
#include <QStyle>
#include <QMessageBox>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
            ui->setupUi(this);
            numTracks = 0;
            QObject::connect(ui->addTrack, SIGNAL(clicked()), this, SLOT(addTrack()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addTrack(){

    TrackGUI *addT = new TrackGUI("Track " + QString::number(numTracks + 1), numTracks);
    ui->verticalLayout->insertLayout(numTracks, addT->track);
    numTracks++;
    addT->trackNumber = tracks.size();
    tracks.push_back(addT);
    QObject::connect(addT->deleteTrack, SIGNAL(clicked()), this, SLOT(removeTrack()));
    sync();

}

//Removes
void MainWindow::sync(){

    for(int i = 0; i < tracks.size(); i++){
        tracks[i]->deleteTrack->setProperty("trackNumber", i);
        tracks[i]->mute->setProperty("trackNumber", i);
        tracks[i]->label->setText("Track " + QString::number(i+1));
    }
    if(numTracks == maxTrack) {
        ui->addTrack->hide();
    }else{
        if(ui->addTrack->isHidden()){
            ui->addTrack->show();
        }
    }

}

void MainWindow::removeTrack(){
    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());
    int trackNumber = buttonSender->property("trackNumber").toInt();
    delete tracks[trackNumber];
    tracks.erase(tracks.begin() + trackNumber);
    numTracks--;
    sync();
}

void MainWindow::quit() {
    QApplication::quit();
}




