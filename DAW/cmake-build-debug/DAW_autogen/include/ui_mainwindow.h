/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *functionBar;
    QPushButton *newProjectButton;
    QPushButton *loadProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *playButton;
    QPushButton *stopPlay;
    QLabel *label;
    QLineEdit *latencyCorrection;
    QSpacerItem *horizontalSpacer;
    QLabel *projectNameLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addTrack;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *tracksLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1437, 886);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 1411, 31));
        functionBar = new QHBoxLayout(horizontalLayoutWidget);
        functionBar->setObjectName("functionBar");
        functionBar->setSizeConstraint(QLayout::SetDefaultConstraint);
        functionBar->setContentsMargins(0, 0, 0, 0);
        newProjectButton = new QPushButton(horizontalLayoutWidget);
        newProjectButton->setObjectName("newProjectButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newProjectButton->sizePolicy().hasHeightForWidth());
        newProjectButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(newProjectButton);

        loadProjectButton = new QPushButton(horizontalLayoutWidget);
        loadProjectButton->setObjectName("loadProjectButton");
        sizePolicy1.setHeightForWidth(loadProjectButton->sizePolicy().hasHeightForWidth());
        loadProjectButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(loadProjectButton);

        deleteProjectButton = new QPushButton(horizontalLayoutWidget);
        deleteProjectButton->setObjectName("deleteProjectButton");
        sizePolicy1.setHeightForWidth(deleteProjectButton->sizePolicy().hasHeightForWidth());
        deleteProjectButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(deleteProjectButton);

        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName("playButton");
        sizePolicy1.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(playButton);

        stopPlay = new QPushButton(horizontalLayoutWidget);
        stopPlay->setObjectName("stopPlay");

        functionBar->addWidget(stopPlay);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        functionBar->addWidget(label);

        latencyCorrection = new QLineEdit(horizontalLayoutWidget);
        latencyCorrection->setObjectName("latencyCorrection");
        sizePolicy1.setHeightForWidth(latencyCorrection->sizePolicy().hasHeightForWidth());
        latencyCorrection->setSizePolicy(sizePolicy1);

        functionBar->addWidget(latencyCorrection);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        functionBar->addItem(horizontalSpacer);

        projectNameLabel = new QLabel(horizontalLayoutWidget);
        projectNameLabel->setObjectName("projectNameLabel");
        sizePolicy.setHeightForWidth(projectNameLabel->sizePolicy().hasHeightForWidth());
        projectNameLabel->setSizePolicy(sizePolicy);

        functionBar->addWidget(projectNameLabel);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 60, 1411, 811));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(25);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 14, 0, 0);
        addTrack = new QPushButton(verticalLayoutWidget);
        addTrack->setObjectName("addTrack");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addTrack->sizePolicy().hasHeightForWidth());
        addTrack->setSizePolicy(sizePolicy3);
        addTrack->setMinimumSize(QSize(40, 30));
        addTrack->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(addTrack);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 40, 281, 22));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tracksLabel = new QLabel(horizontalLayoutWidget_3);
        tracksLabel->setObjectName("tracksLabel");
        tracksLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(tracksLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        newProjectButton->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        deleteProjectButton->setText(QCoreApplication::translate("MainWindow", "Delete Project", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play All", nullptr));
        stopPlay->setText(QCoreApplication::translate("MainWindow", "Stop Playback", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Latency Corection (ms): ", nullptr));
        projectNameLabel->setText(QCoreApplication::translate("MainWindow", "Project: Project1", nullptr));
        addTrack->setText(QCoreApplication::translate("MainWindow", "Add Track", nullptr));
        tracksLabel->setText(QCoreApplication::translate("MainWindow", "Tracks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
