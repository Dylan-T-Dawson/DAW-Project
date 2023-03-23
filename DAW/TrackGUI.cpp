//
// Created by dtda230 on 3/22/2023.
//

#include "TrackGUI.h"

TrackGUI::TrackGUI(QString name, int trackNum){
    trackNumber = trackNum;
    trackName = name;
    label->setText(trackName);
    label->setAlignment(Qt::AlignHCenter);
    mute->setText("Mute");
    mute->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    mute->setMinimumSize(80, 25);
    mute->setMaximumSize(80, 25);
    volume->setOrientation(Qt::Orientation::Horizontal);
    volume->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    volume->setMinimumSize(175, 20);
    volume->setMaximumSize(175, 20);

    deleteTrack->setText("Delete");
    deleteTrack->setMinimumSize(80, 25);
    deleteTrack->setMaximumSize(80, 25);
    deleteTrack->setAutoRepeatDelay(trackNumber);
    trackHandle->setHorizontalSpacing(7);
    trackHandle->setVerticalSpacing(7);
    trackHandle->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::FieldsStayAtSizeHint);
    trackHandle->setRowWrapPolicy(QFormLayout::RowWrapPolicy::DontWrapRows);
    trackHandle->setLabelAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    trackHandle->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    trackHandle->setSizeConstraint(QFormLayout::SetDefaultConstraint);

    muteLayout = new QHBoxLayout;
    muteLayout->addWidget(label);
    muteLayout->addWidget(mute);


    volumeLayout = new QHBoxLayout;
    volumeLayout->setContentsMargins(25,0,0,0);
    volumeLayout->addWidget(volume);
    volumeLayout->addWidget(deleteTrack);

    trackHandle->addRow(muteLayout);
    trackHandle->addRow(volumeLayout);

    visual->setMaximumSize(1109, 67);
    visual->setMinimumSize(1109, 67);
    track->addLayout(trackHandle);
    track->addWidget(visual);
    track->setContentsMargins(0, 2, 0, 2);
    track->setSpacing(15);
    track->setSizeConstraint(QLayout::SetDefaultConstraint);

}

TrackGUI::~TrackGUI()
{
    // remove track layout from its parent layout

    // delete all widgets and layouts within trackHandle
    QLayoutItem* item;
    while ((item = muteLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            trackHandle->removeWidget(widget);
            delete widget;
        }
        else {
            delete item;
        }
    }
    while ((item = volumeLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            trackHandle->removeWidget(widget);
            delete widget;
        }
        else {
            delete item;
        }
    }
    while ((item = trackHandle->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            trackHandle->removeWidget(widget);
            delete widget;
        }
        else {
            delete item;
        }
    }

    // delete trackHandle and track
    delete trackHandle;
    delete visual;
    delete track;
}
