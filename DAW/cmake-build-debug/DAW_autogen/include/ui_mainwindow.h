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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QPushButton *exportButton;
    QPushButton *newProjectButton;
    QPushButton *loadProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *playButton;
    QPushButton *recordButton;
    QPushButton *pitchButton;
    QPushButton *fadeButton;
    QPushButton *copyPasteButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *trackHandle_7;
    QLabel *label_13;
    QPushButton *muteButton_7;
    QSlider *horizontalSlider_8;
    QPushButton *deleteButton_8;
    QGraphicsView *graphicsView_5;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *trackHandle_6;
    QLabel *label_12;
    QPushButton *muteButton_6;
    QSlider *horizontalSlider_7;
    QPushButton *deleteButton_7;
    QGraphicsView *graphicsView_4;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *trackHandle_5;
    QLabel *label_11;
    QPushButton *muteButton_5;
    QSlider *horizontalSlider_6;
    QPushButton *deleteButton_6;
    QGraphicsView *graphicsView_3;
    QPushButton *addTrack;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_0;
    QLabel *label_30;
    QLabel *label_100;
    QLabel *label_130;
    QLabel *label_200;
    QLabel *label_250;
    QLabel *label_300;
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
        exportButton = new QPushButton(horizontalLayoutWidget);
        exportButton->setObjectName("exportButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(exportButton);

        newProjectButton = new QPushButton(horizontalLayoutWidget);
        newProjectButton->setObjectName("newProjectButton");
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

        recordButton = new QPushButton(horizontalLayoutWidget);
        recordButton->setObjectName("recordButton");
        sizePolicy1.setHeightForWidth(recordButton->sizePolicy().hasHeightForWidth());
        recordButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(recordButton);

        pitchButton = new QPushButton(horizontalLayoutWidget);
        pitchButton->setObjectName("pitchButton");
        sizePolicy1.setHeightForWidth(pitchButton->sizePolicy().hasHeightForWidth());
        pitchButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(pitchButton);

        fadeButton = new QPushButton(horizontalLayoutWidget);
        fadeButton->setObjectName("fadeButton");
        sizePolicy1.setHeightForWidth(fadeButton->sizePolicy().hasHeightForWidth());
        fadeButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(fadeButton);

        copyPasteButton = new QPushButton(horizontalLayoutWidget);
        copyPasteButton->setObjectName("copyPasteButton");
        sizePolicy1.setHeightForWidth(copyPasteButton->sizePolicy().hasHeightForWidth());
        copyPasteButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(copyPasteButton);

        deleteButton = new QPushButton(horizontalLayoutWidget);
        deleteButton->setObjectName("deleteButton");
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);

        functionBar->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        functionBar->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        functionBar->addWidget(label);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 60, 1411, 811));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(25);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 14, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(15);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, 2, 0, 2);
        trackHandle_7 = new QFormLayout();
        trackHandle_7->setObjectName("trackHandle_7");
        trackHandle_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        trackHandle_7->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        trackHandle_7->setLabelAlignment(Qt::AlignCenter);
        trackHandle_7->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");

        trackHandle_7->setWidget(0, QFormLayout::LabelRole, label_13);

        muteButton_7 = new QPushButton(verticalLayoutWidget);
        muteButton_7->setObjectName("muteButton_7");

        trackHandle_7->setWidget(0, QFormLayout::FieldRole, muteButton_7);

        horizontalSlider_8 = new QSlider(verticalLayoutWidget);
        horizontalSlider_8->setObjectName("horizontalSlider_8");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider_8->sizePolicy().hasHeightForWidth());
        horizontalSlider_8->setSizePolicy(sizePolicy2);
        horizontalSlider_8->setMinimumSize(QSize(175, 20));
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        trackHandle_7->setWidget(1, QFormLayout::LabelRole, horizontalSlider_8);

        deleteButton_8 = new QPushButton(verticalLayoutWidget);
        deleteButton_8->setObjectName("deleteButton_8");

        trackHandle_7->setWidget(1, QFormLayout::FieldRole, deleteButton_8);


        horizontalLayout_7->addLayout(trackHandle_7);

        graphicsView_5 = new QGraphicsView(verticalLayoutWidget);
        graphicsView_5->setObjectName("graphicsView_5");
        sizePolicy.setHeightForWidth(graphicsView_5->sizePolicy().hasHeightForWidth());
        graphicsView_5->setSizePolicy(sizePolicy);
        graphicsView_5->setMinimumSize(QSize(1109, 67));
        graphicsView_5->setMaximumSize(QSize(1109, 67));

        horizontalLayout_7->addWidget(graphicsView_5);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 2, 0, 2);
        trackHandle_6 = new QFormLayout();
        trackHandle_6->setObjectName("trackHandle_6");
        trackHandle_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        trackHandle_6->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        trackHandle_6->setLabelAlignment(Qt::AlignCenter);
        trackHandle_6->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");

        trackHandle_6->setWidget(0, QFormLayout::LabelRole, label_12);

        muteButton_6 = new QPushButton(verticalLayoutWidget);
        muteButton_6->setObjectName("muteButton_6");

        trackHandle_6->setWidget(0, QFormLayout::FieldRole, muteButton_6);

        horizontalSlider_7 = new QSlider(verticalLayoutWidget);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        sizePolicy2.setHeightForWidth(horizontalSlider_7->sizePolicy().hasHeightForWidth());
        horizontalSlider_7->setSizePolicy(sizePolicy2);
        horizontalSlider_7->setMinimumSize(QSize(175, 20));
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        trackHandle_6->setWidget(1, QFormLayout::LabelRole, horizontalSlider_7);

        deleteButton_7 = new QPushButton(verticalLayoutWidget);
        deleteButton_7->setObjectName("deleteButton_7");

        trackHandle_6->setWidget(1, QFormLayout::FieldRole, deleteButton_7);


        horizontalLayout_6->addLayout(trackHandle_6);

        graphicsView_4 = new QGraphicsView(verticalLayoutWidget);
        graphicsView_4->setObjectName("graphicsView_4");
        sizePolicy.setHeightForWidth(graphicsView_4->sizePolicy().hasHeightForWidth());
        graphicsView_4->setSizePolicy(sizePolicy);
        graphicsView_4->setMinimumSize(QSize(1109, 67));
        graphicsView_4->setMaximumSize(QSize(1109, 67));

        horizontalLayout_6->addWidget(graphicsView_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 2, 0, 2);
        trackHandle_5 = new QFormLayout();
        trackHandle_5->setObjectName("trackHandle_5");
        trackHandle_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        trackHandle_5->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        trackHandle_5->setLabelAlignment(Qt::AlignCenter);
        trackHandle_5->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");

        trackHandle_5->setWidget(0, QFormLayout::LabelRole, label_11);

        muteButton_5 = new QPushButton(verticalLayoutWidget);
        muteButton_5->setObjectName("muteButton_5");

        trackHandle_5->setWidget(0, QFormLayout::FieldRole, muteButton_5);

        horizontalSlider_6 = new QSlider(verticalLayoutWidget);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        sizePolicy2.setHeightForWidth(horizontalSlider_6->sizePolicy().hasHeightForWidth());
        horizontalSlider_6->setSizePolicy(sizePolicy2);
        horizontalSlider_6->setMinimumSize(QSize(175, 20));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        trackHandle_5->setWidget(1, QFormLayout::LabelRole, horizontalSlider_6);

        deleteButton_6 = new QPushButton(verticalLayoutWidget);
        deleteButton_6->setObjectName("deleteButton_6");

        trackHandle_5->setWidget(1, QFormLayout::FieldRole, deleteButton_6);


        horizontalLayout_5->addLayout(trackHandle_5);

        graphicsView_3 = new QGraphicsView(verticalLayoutWidget);
        graphicsView_3->setObjectName("graphicsView_3");
        sizePolicy.setHeightForWidth(graphicsView_3->sizePolicy().hasHeightForWidth());
        graphicsView_3->setSizePolicy(sizePolicy);
        graphicsView_3->setMinimumSize(QSize(1109, 67));
        graphicsView_3->setMaximumSize(QSize(1109, 67));

        horizontalLayout_5->addWidget(graphicsView_3);


        verticalLayout->addLayout(horizontalLayout_5);

        addTrack = new QPushButton(verticalLayoutWidget);
        addTrack->setObjectName("addTrack");
        sizePolicy2.setHeightForWidth(addTrack->sizePolicy().hasHeightForWidth());
        addTrack->setSizePolicy(sizePolicy2);
        addTrack->setMinimumSize(QSize(40, 30));
        addTrack->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(addTrack);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(310, 40, 1111, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_0 = new QLabel(horizontalLayoutWidget_2);
        label_0->setObjectName("label_0");

        horizontalLayout->addWidget(label_0);

        label_30 = new QLabel(horizontalLayoutWidget_2);
        label_30->setObjectName("label_30");

        horizontalLayout->addWidget(label_30);

        label_100 = new QLabel(horizontalLayoutWidget_2);
        label_100->setObjectName("label_100");

        horizontalLayout->addWidget(label_100);

        label_130 = new QLabel(horizontalLayoutWidget_2);
        label_130->setObjectName("label_130");

        horizontalLayout->addWidget(label_130);

        label_200 = new QLabel(horizontalLayoutWidget_2);
        label_200->setObjectName("label_200");

        horizontalLayout->addWidget(label_200);

        label_250 = new QLabel(horizontalLayoutWidget_2);
        label_250->setObjectName("label_250");

        horizontalLayout->addWidget(label_250);

        label_300 = new QLabel(horizontalLayoutWidget_2);
        label_300->setObjectName("label_300");

        horizontalLayout->addWidget(label_300);

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
        exportButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        newProjectButton->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        deleteProjectButton->setText(QCoreApplication::translate("MainWindow", "Delete Project", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        recordButton->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        pitchButton->setText(QCoreApplication::translate("MainWindow", "Shift Pitch", nullptr));
        fadeButton->setText(QCoreApplication::translate("MainWindow", "Fade In/Out", nullptr));
        copyPasteButton->setText(QCoreApplication::translate("MainWindow", "Copy Selected", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Project: Project1", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Track 1", nullptr));
        muteButton_7->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
        deleteButton_8->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Track 2", nullptr));
        muteButton_6->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
        deleteButton_7->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Track 3", nullptr));
        muteButton_5->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
        deleteButton_6->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        addTrack->setText(QCoreApplication::translate("MainWindow", "Add Track", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_100->setText(QCoreApplication::translate("MainWindow", "1:00", nullptr));
        label_130->setText(QCoreApplication::translate("MainWindow", "1:30", nullptr));
        label_200->setText(QCoreApplication::translate("MainWindow", "2:00", nullptr));
        label_250->setText(QCoreApplication::translate("MainWindow", "2:30", nullptr));
        label_300->setText(QCoreApplication::translate("MainWindow", "3:00", nullptr));
        tracksLabel->setText(QCoreApplication::translate("MainWindow", "Tracks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
