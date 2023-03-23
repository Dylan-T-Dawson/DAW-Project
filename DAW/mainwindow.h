#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "QLRClickButton.h"
#include <vector>
#include <memory>
#include "TrackGUI.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private slots:

    void addTrack();

    static void quit();

private:
    Ui::MainWindow* ui;
    int numTracks;
};

#endif // MAINWINDOW_H