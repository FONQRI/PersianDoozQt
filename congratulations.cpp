#include "congratulations.h"


#include <QPropertyAnimation>
#include <QString>
#include <QDebug>
Congratulations::Congratulations(QWidget *parent):QWidget(parent)
{
    //set color
    setStyleSheet("background-color: orange");

    //set geometry
    setGeometry(600,400,0,0);
    setFixedSize(710,435);

    QString congratulations;
    congratulations="  Congratulations ";

    congratulations.append(v->PlayerName[v->turn]);
    congratulations.append(" You WIN");
    con=new QLabel(congratulations,this);
    con->setStyleSheet("background-color:green;color:#16beeb");
    con->show();
    QPropertyAnimation *animation=new QPropertyAnimation(con,"geometry");
    animation->setDuration(2000);
    animation->setStartValue(QRect(p(8,1).x(),p(8,1).y(),250,25));


    animation->setKeyValueAt(0.09,QRect(p(5.5,3).x(),p(5.5,3).y(),250,25));
    animation->setKeyValueAt(0.18,QRect(p(3,4.5).x(),p(3,4.5).y(),250,25));
    animation->setKeyValueAt(0.27,QRect(p(4,9).x(),p(4,9).y(),250,25));
    animation->setKeyValueAt(0.36,QRect(p(5.5,11).x(),p(5.5,11).y(),250,25));
    animation->setKeyValueAt(0.45,QRect(p(9,11).x(),p(9,11).y(),250,25));
    animation->setKeyValueAt(0.54,QRect(p(11,10).x(),p(11,10).y(),250,25));
    animation->setKeyValueAt(0.63,QRect(p(12,8).x(),p(12,8).y(),250,25));
    animation->setKeyValueAt(0.72,QRect(p(11,6).x(),p(11,6).y(),250,25));
    animation->setKeyValueAt(0.81,QRect(p(8,5).x(),p(8,5).y(),250,25));
    animation->setKeyValueAt(0.90,QRect(p(6,6).x(),p(6,6).y(),250,25));
    animation->setKeyValueAt(0.99,QRect(p(7,7).x(),p(7,7).y(),250,25));

    animation->setEndValue(QRect(210,192.5,250,25));
    animation->start();


    //creat Back button
    Back=new QPushButton(this);
    Back->setStyleSheet("background-color :#ff0000;border:2px solid #000000;border-radius: 5px;color:#000000");
    Back->setGeometry(20,30,100,50);
    Back->setText("Back");

    //creat Exit button
    Exit=new QPushButton(this);
    Exit->setStyleSheet("background-color :#ff0000;border:2px solid #000000;border-radius: 5px;color:#000000");
    Exit->setGeometry(590,30,100,50);
    Exit->setText("Exit");
    //connectins signal and slots
    connect(Back,SIGNAL(clicked(bool)),this,SLOT(back()));
    connect(Exit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

QPointF Congratulations::p(float x, float y)
{
    x *=38.3;
    y *=34.1;
    return QPointF(x,y);
}

void Congratulations::back()
{
    start=new StartWidget();
    v=new Variables();
    start->show();
    this->close();
}
