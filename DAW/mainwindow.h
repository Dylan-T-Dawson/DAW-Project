#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "QLRClickButton.h"
#include <vector>
#include <memory>
#include "TrackGUI.h"

#define maxTrack 8

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
    void removeTrack();
    void sync();
    static void quit();

private:
    Ui::MainWindow* ui;
    int numTracks;
    std::vector<TrackGUI*> tracks;
};

#endif // MAINWINDOW_H