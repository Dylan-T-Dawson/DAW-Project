
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


}

MainWindow::~MainWindow() {
    delete ui;
}

//Closes the application when the Quit button is clicked.
void MainWindow::quit() {
    QApplication::quit();
}




