#pragma once
#ifndef GAME_H
#define GAME_H
#include<QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPushButton>
#include <QGraphicsTextItem>


#include "player.h"
#include "variables.h"
#include "congratulations.h"


extern  Variables *v;


class Game:public QGraphicsView
{
    Q_OBJECT


public:
    Game(QWidget *parent=0);

    //player functions
    void player1();
    void player2();

    //playgame function
    void PlayGame();

    //function for setting turn
    void setTurn();

    //winner function
    void Winner();
    void win();

    //timer
    QGraphicsTextItem *playtime;

    QTimer *playertime;

    //congratulations window
    Congratulations *w;

    //tow player mod
    TowBlack *Player;

    //seconds
    int seconds;





    private:


    //creating scene
    QGraphicsScene *scene;

    //backPushButton
    QPushButton *BackButton;
    //Exit PushButton
    QPushButton *ExitButton;



    //
    QGraphicsTextItem *Player1NameLabel;
    QGraphicsTextItem *Player2NameLabel;

public slots:
    void back();
    void devrasesec();









};

#endif // GAME_H
