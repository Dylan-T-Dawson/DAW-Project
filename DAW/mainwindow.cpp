
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

}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::addTrack(){

    for(int i = 0; i < 5; i++) {
        TrackGUI *addT = new TrackGUI("Track " + QString::number(i), i);
        ui->verticalLayout->insertLayout(i, addT->track);
    }

}

void MainWindow::quit() {
    QApplication::quit();
}




