//
// Created by dtda230 on 3/20/2023.
//
//See header file for additional authorship details.

#include "QLRClickButton.h"

QLRClickButton::QLRClickButton(QWidget *parent) :
QPushButton(parent){

}

void QLRClickButton::mousePressEvent(QMouseEvent *c){
    if(c->button() == Qt::RightButton){
        emit rightClicked();
    }
    if(c->button() == Qt::LeftButton){
        emit clicked();
    }
}