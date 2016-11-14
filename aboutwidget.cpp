#include "aboutwidget.h"
#include "startwidget.h"
#include <QMovie>
AboutWidget::AboutWidget(QWidget *parent):QWidget(parent)
{
    //set size of window
    setGeometry(600,400,0,0);
    setFixedSize(710,435);
    //set color
    setStyleSheet("background-color:#4c69f6");

    //set back button
    Back = new QPushButton(tr("Back"),this);
    Back->setGeometry(30,30,150,75);
    Back->setStyleSheet("background-color: #4c94f6;border:2px solid #007de3;border-radius: 5px");

    //connecting slot
    connect(Back,SIGNAL(clicked(bool)),this,SLOT(back()));

    //set Info Label
    Info=new QLabel(this);
    Info->setStyleSheet("background-color: #f6db35;border:2px solid #007de3;border-radius: 5px");


    Info->setGeometry(210,30,480,345);
    Info->setText("Hi\nI'm Behnam Sabaghi . I'm a software developer and i hope to you enjoy this game .\n\n"
                  "This game is a simple dooz for you\n\n\n\n\nPhone Number :    +989384797401\n\nEmail :"
                  "behnamsabaghi@gmail.com\n\nWeb :http://myprogrammingworks.blog.ir");

    Info->setFont(QFont("Circulate BRK",14,2,true));
    Info->setWordWrap(true);
    Info->setAlignment(Qt::AlignAbsolute);
}

void AboutWidget::back()
{
    StartWidget *Start=new StartWidget();
    Start->show();
    this->close();
}

