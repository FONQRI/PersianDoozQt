#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
class Variables
{
public:
    Variables();
    int arry[14][7];
    int Xplace[3];
    int turn;// 1 for Tow one 2 for Tow 2 and 0 for AI
    bool gameMood;//false for tow player and true for single player
    int winner;// 1 for Tow one 2 for Tow 2 and 0 for AI
    int LastPlaceXPlayer1;//for storing last place of x for player 1
    int LastPlaceXPlayer2;//for storing last place of x for player 2
    QString PlayerName[3];
    //set turn tow
    QGraphicsPixmapItem *turnIcon=new QGraphicsPixmapItem();





};

#endif // VARIABLES_H
