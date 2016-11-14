#include "player.h"
#include <QPixmap>
#include "Game.h"

extern Game *game;

#include <QDebug>


TowBlack::TowBlack(QGraphicsItem *parent):QObject() , QGraphicsPixmapItem(parent)
{
    //set QPixmap
    if(v->turn == 2)
    {
        setPixmap(QPixmap(":/images/OrangeTaw.png"));
        v->turnIcon->setPos(525,19);
    }
    else
    {
        setPixmap(QPixmap(":/images/BlackTaw.png"));
        v->turnIcon->setPos(167,19);
    }



    //set pos

    setX(27 + v->Xplace[v->turn]*47);
    setY(50);
    Xplace=v->Xplace[v->turn];

}





void TowBlack::keyPressEvent(QKeyEvent *event)
{

    switch (event->key())
    {

    case Qt::Key_Left:

        // move to left
        MoveLeft();
        break;
    case Qt::Key_Right:
        //move to right
        MoveRight();
        break;
    case Qt::Key_Down:
        //move down by qtimer

        MoveDown();
        break;
    default:
        break;
    }
}

void TowBlack::MoveLeft()
{

    if(moving)
    {
        return;
    }
    if(Xplace > 0)
    {
        moving=true;
        //set animation
        QPropertyAnimation *animation=new QPropertyAnimation(this,"pos");
        animation->setDuration(150);
        animation->setStartValue(QPointF(x(),y()));
        animation->setEndValue(QPointF( x()- 47, y()));
        animation->start();

        //set timer
        connect(movingtime,SIGNAL(timeout()),this,SLOT(changeMoveValue()));
        movingtime->setSingleShot(true);
        movingtime->start(200);


        Xplace--;
    }
}

void TowBlack::MoveRight()
{
    if(moving )
    {
        return;
    }

    if(Xplace < 13)
    {
        moving=true;
        //set animation
        QPropertyAnimation *animation=new QPropertyAnimation(this,"pos");
        animation->setDuration(150);
        animation->setStartValue(QPointF(x(),y()));
        animation->setEndValue(QPointF( x()+ 47, y()));
        animation->start();

        //set timer

        movingtime->setSingleShot(true);
        connect(movingtime,SIGNAL(timeout()),this,SLOT(changeMoveValue()));
        movingtime->setInterval(200);
        movingtime->start();



        Xplace++;
    }
}




void TowBlack::MoveDown()
{

    if( v->arry[Xplace][0] > -1 )
        return;
    if(moving)
        return;
    moving =true;
    //test************************
    Yplace = emptyY(Xplace);


    game->seconds=90;

    QPropertyAnimation *animation=new QPropertyAnimation(this,"pos");
    animation->setDuration(1000);
    animation->setStartValue(QPointF(x(),50));
    animation->setEndValue(QPointF( x(), 103 + Yplace* 40));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    //doing logical move


    connect(t,SIGNAL(timeout()),this,SLOT(doNext()));
    t->setSingleShot(true);

    t->start(1000);



}

void TowBlack::changeTurn()
{
    if(! v->gameMood)
    {
        if(v->turn == 1)
        {
            v->turn= 2 ;
        }
        else
        {
            v->turn=1;
        }
    }
    if( v->gameMood)
    {
        if(v->turn == 1)
        {
            v->turn= 0 ;
        }
        else
        {
            v->turn=1;
        }
    }


}

int TowBlack::emptyY(int x)
{
    int i;
    for( i=0;i<6;i++)
        if(v->arry[x][i+ 1] != -1)
        {
            if(i> 6)
            {
                i--;
            }
            break;
        }
    return i ;
}



void TowBlack::doNext()
{
    v->Xplace[v->turn]=Xplace;
    v->arry[Xplace][Yplace]=v->turn;
    //check win
    game->Winner();
    changeTurn();
    game->PlayGame();
    return;

}

void TowBlack::changeMoveValue()
{
    moving=false;

}

