#pragma once
#ifndef TOWBLACK_H
#define TOWBLACK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPropertyAnimation>

#include "variables.h"
extern Variables *v;
class TowBlack:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    TowBlack(QGraphicsItem *parent =0);

    void keyPressEvent(QKeyEvent *event);

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void changeTurn();
    //player timer



private:

    int Xplace;// 1 for TowBlack one 2 for TowBlack 2 and 0 for AI and
    int Yplace;// 1 for TowBlack one 2 for TowBlack 2 and 0 for AI and

    QTimer *t=new QTimer();
    QTimer *movingtime=new QTimer();




    //creat a variable for first time down is running
    bool firstdown = true;

    //a variable for running down
    bool moving =false;


    int emptyY(int x);
    //player timer
    //


public slots:

    void doNext();
    void changeMoveValue();




};

#endif // TOWBLACK_H
