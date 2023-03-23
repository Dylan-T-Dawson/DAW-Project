
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
            addTrack();
        QObject::connect(ui->addTrack, SIGNAL(clicked()), this, SLOT(addTrack()));
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::addTrack(){


    TrackGUI *addT = new TrackGUI("Track " + QString::number(numTracks), numTracks);
    ui->verticalLayout->insertLayout(numTracks, addT->track);
    numTracks++;
    addT->trackNumber = tracks.size();
    tracks.push_back(addT);
    QObject::connect(addT->deleteTrack, SIGNAL(clicked()), this, SLOT(removeTrack()));
    sync();

}

//Removes
void MainWindow::sync(){

    QPushButton *addTrackButton = qobject_cast<QPushButton *>(ui->verticalLayout->itemAt(numTracks)->widget());
    if(numTracks == maxTrack) {
        addTrackButton->hide();
    }else{
        if(addTrackButton->isHidden()){
            //MAKE THIS HAPPEN.
            addTrackButton->show();
        }
    }

}

void MainWindow::removeTrack(){
    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender());
    std::cout << buttonSender->autoRepeatDelay();
    delete tracks[buttonSender->autoRepeatDelay()];
    for(int i = buttonSender->autoRepeatDelay(); i < tracks.size()-1; i++){
        tracks[i] = tracks[i]++;
    }
    tracks.pop_back();
    numTracks--;


}

void MainWindow::quit() {
    QApplication::quit();
}




