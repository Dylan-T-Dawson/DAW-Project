//
// Created by dtda230 on 3/20/2023.
//


/*The following code is adapted from a response to a question asked by another user on stack Overflow.
 * The original author's link is https://stackoverflow.com/users/1288414/md-minhazul-haque and the answer from
 * which I adapted the code can be found here: https://stackoverflow.com/questions/15658464/qt-rightclick-qpushbutton
 * The following code is a simple method of creating an extension of the QPushButton class, which also inherits from the
 * Q_Object class. The new QLRClickButton can be used to detect both left and right mouse clicks.
*/


#ifndef MINESWEEPER_QLRCLICKBUTTON_H
#define MINESWEEPER_QLRCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class QLRClickButton : public QPushButton {
Q_OBJECT

public:
    explicit QLRClickButton(QWidget *parent = 0);

private slots:

    void mousePressEvent(QMouseEvent *c);

signals:

    void rightClicked();

};


#endif //MINESWEEPER_QLRCLICKBUTTON_H
