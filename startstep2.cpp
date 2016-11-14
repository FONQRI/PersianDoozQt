#include "startstep2.h"
#include "Game.h"

#include <QDebug>
extern Game *game;

StartStep2::StartStep2(QWidget *parent):QWidget(parent)
{
    //set size of window
    setGeometry(600,400,0,0);
    setFixedSize(710,435);


    //set color
    setStyleSheet("background-color:#4c69f6");

    //set labels
    player1Name=new QLabel(tr("Green Player Name :"),this);
    player1Name->setGeometry(30,30,150,25);
    player1Name->setStyleSheet("background-color: #4c69f6;border:2px solid #007de3;border-radius: 5px;color:#000000");

    player2Name=new QLabel(tr("Red Player Name :"),this);
    player2Name->setGeometry(30,60,150,25);
    player2Name->setStyleSheet("background-color: #4c69f6;border:2px solid #007de3;border-radius: 5px;color:#000000");

    //set line edits
    player1=new QLineEdit(this);
    player1->setGeometry(190,30,150,25);
    player1->setStyleSheet("background-color: #ffffff;border:2px solid #000000;border-radius: 5px;color:#000000");

    player2=new QLineEdit(this);
    player2->setGeometry(190,60,150,25);
    player2->setStyleSheet("background-color: #ffffff;border:2px solid #000000;border-radius: 5px;color:#000000");

    //set start button
    startGame=new QPushButton(tr("start Game"),this);
    startGame->setGeometry(550,30,150,75);
    startGame->setStyleSheet("background-color: #4c94f6;border:2px solid #007de3;border-radius: 5px");


    //set back button
    Back = new QPushButton(tr("Back"),this);
    Back->setGeometry(550,115,150,75);
    Back->setStyleSheet("background-color: #4c94f6;border:2px solid #007de3;border-radius: 5px");

    //set Exit button
    Exit=new QPushButton(tr("Exit"),this);
    Exit->setGeometry(550,200,150,75);
    Exit->setStyleSheet("background-color: #4c94f6;border:2px solid #007de3;border-radius: 5px");

    //connecting slot
    connect(Back,SIGNAL(clicked(bool)),this,SLOT(back()));
    connect(Exit,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(startGame,SIGNAL(clicked(bool)),this,SLOT(startgame()));


}

void StartStep2::back()
{
    start=new StartWidget();
    start->show();
    this->close();
}

void StartStep2::startgame()
{
    if(player1->text()!=__null && player2->text() !=__null)
    {
        v->PlayerName[1]=player1->text();
        v->PlayerName[2]=player2->text();
        game=new Game();
        game->show();
        this->close();
    }
     if(player1->text()==__null)
    {
        error=new QLabel(tr("You Must Enert A Name"),this);
        error->setGeometry(350,30,170,25);
        error->setStyleSheet("background-color: #ffe700;border:2px solid #007de3;border-radius: 5px;color:#ff0000");
        error->show();
        connect(player1,SIGNAL(textChanged(QString)),error,SLOT(hide()));
    }
     if(player2->text()==__null)
    {
        error=new QLabel(tr("You Must Enert A Name"),this);
        error->setGeometry(350,60,170,25);
        error->setStyleSheet("background-color: #ffe700;border:2px solid #007de3;border-radius: 5px;color:#ff0000");
        error->show();
        connect(player2,SIGNAL(textChanged(QString)),error,SLOT(hide()));
    }

}
