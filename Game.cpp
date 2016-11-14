#include "Game.h"
#include <QGraphicsRectItem>
#include <stdlib.h>
#include <QTimer>
#include<QDebug>


#include "startwidget.h"
Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //set second
    seconds=90;
    //set scene
    scene=new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0,0,707,429);

    //set background Brush
    setBackgroundBrush(QBrush(QImage(":/images/BoardGame.png")));

    //set QGraphicsView size
    setGeometry(600,400,0,0);
    setFixedSize(710,435);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    //game

    setTurn();
    PlayGame();


    //timer
    playtime=new QGraphicsTextItem();
    scene->addItem(playtime);
    playtime->setPos(340,390);
    playertime=new QTimer();
    connect(playertime,SIGNAL(timeout()),this,SLOT(devrasesec()));
    playertime->setInterval(1000);
    playertime->start();
    //drow timer
    playtime->setPlainText( QString::number(seconds));//  90

    playtime->setDefaultTextColor(Qt::green);
    playtime->setFont(QFont("times",16));





    //back button
    BackButton = new QPushButton();
    BackButton->setGeometry(20,405,150,25);
    BackButton->setText("Back To Menu");
    scene->addWidget(BackButton);
    BackButton->setStyleSheet("background-color: #00c700;border:2px solid #000000;border-radius: 1.5px;");


    //Exit button
    ExitButton = new QPushButton();
    ExitButton->setGeometry(530,405,150,25);
    ExitButton->setText("Exit");
    scene->addWidget(ExitButton);
    ExitButton->setStyleSheet("background-color: red;border:2px solid #000000;border-radius: 1.5px;");


    //connnect signal and slots
    connect(BackButton,SIGNAL(clicked(bool)),this,SLOT(back()));
    connect(ExitButton,SIGNAL(clicked(bool)),this,SLOT(close()));


    //set player names
    Player1NameLabel=new QGraphicsTextItem;
    Player1NameLabel->setPlainText(v->PlayerName[1]);
    Player1NameLabel->setDefaultTextColor(Qt::cyan);
    Player1NameLabel->setFont(QFont("times",17,20,true));
    scene->addItem(Player1NameLabel);
    Player1NameLabel->setPos(35,9);

    Player2NameLabel=new QGraphicsTextItem;
    Player2NameLabel->setPlainText(v->PlayerName[2]);
    Player2NameLabel->setDefaultTextColor(Qt::cyan);
    Player2NameLabel->setFont(QFont("times",17,20,true));
    scene->addItem(Player2NameLabel);
    Player2NameLabel->setPos(545,9);


    //add turn tow

    scene->addItem(v->turnIcon);
}

void Game::player2()
{
    Player=new TowBlack();
    scene->addItem(Player);
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
}

void Game::player1()
{
    Player=new TowBlack();
    scene->addItem(Player);
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
}

void Game::PlayGame()
{


    if(v->gameMood == false)//TowOrange player mood *****************************
    {




        if(v->turn == 1)
            player1();
        else
            player2();


    }
    else// single player mood *********************************************
    {



    }
}

void Game::setTurn()
{
    if(v->gameMood)
        v->turn=rand()%2;
    else
        v->turn=rand()%2 +1;
}
//***********************************winer**************************
void Game::Winner()
{
    //for row win

    for(int j=0;j<=6;j++)
        for(int i=0;i<=10;i++)
            if(v->arry[i][j]==v->turn && v->arry[i+1][j]==v->turn && v->arry[i+2][j]==v->turn && v->arry[i+3][j]==v->turn )
            {
                v->winner=v->turn;
                win();
                return;
            }
    //for coulmn win

    for(int j=0;j<=3;j++)
        for(int i=0;i<=13;i++)
            if(v->arry[i][j]==v->turn && v->arry[i][j+1]==v->turn && v->arry[i][j+2]==v->turn && v->arry[i][j+3]==v->turn )
            {
                v->winner=v->turn;

                win();
                return;
            }
    //for coulmn row up win

    for(int j=0;j<=3;j++)
        for(int i=0;i<=10;i++)
            if(v->arry[i][j]==v->turn && v->arry[i+1][j+1]==v->turn && v->arry[i+2][j+2]==v->turn && v->arry[i+3][j+3]==v->turn )
            {
                v->winner=v->turn;

                win();
                return;
            }

    //for coulmn row down win
    for(int j=3;j<=6;j++)
        for(int i=3;i<=13;i++)
            if(v->arry[i][j]==v->turn && v->arry[i-1][j+1]==v->turn && v->arry[i-2][j+2]==v->turn && v->arry[i-3][j+3]==v->turn )
            {
                v->winner=v->turn;

                win();
                return;
            }

}

void Game::win()
{

    this->close();
    w=new Congratulations();
    w->show();


}

void Game::back()
{
    StartWidget *Start=new StartWidget();
    v=new Variables();
    Start->show();
    this->close();
}

void Game::devrasesec()
{
        if(seconds == 0 )
        {
            win();
            playertime->stop();
            return;

        }
        seconds--;
        if(seconds <10)
        {
            playtime->setDefaultTextColor(Qt::red);
            playtime->setPos(345,390);
        }

        playtime->setPlainText( QString::number(seconds));// 89
}

