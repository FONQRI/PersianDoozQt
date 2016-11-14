#include "startwidget.h"
#include "Game.h"
#include "aboutwidget.h"
#include "startstep2.h"
extern Game *game;
#include <QDebug>
StartWidget::StartWidget(QWidget *parent):QWidget(parent)
{

    //set size of window
    setGeometry(600,400,0,0);
    setFixedSize(710,435);

    // create Single Player Button
    SinglePlayerButton = new QPushButton(tr("Single Player"),this);
    SinglePlayerButton->setGeometry(50,30,150,75);

    // create Tow Players Button
    TwoPlayersButton = new QPushButton("Two Players",this);
    TwoPlayersButton->setGeometry(50,120,150,75);

    // create About Button
    AboutButton = new QPushButton("About",this);
    AboutButton->setGeometry(50,210,150,75);

    // create Exit Button
    ExtiButton = new QPushButton("Exit",this);
    ExtiButton->setGeometry(50,300,150,75);

    //set image label
    StartImageLabel =new QLabel(this);
    StartImageLabel->setGeometry(210,30,480,345);
    StartImageLabel->setStyleSheet("background-color :lightblue;border:2px solid #007de3;border-radius: 5px");
    Image=new QPixmap(":/images/Start.png");
    StartImageLabel->setPixmap(*Image);

    //set signals and slots
    connect(SinglePlayerButton,SIGNAL(clicked(bool)),this,SLOT(SinglePlayer()));
    connect(TwoPlayersButton,SIGNAL(clicked(bool)),this,SLOT(TowPlayer()));
    connect(AboutButton,SIGNAL(clicked(bool)),this,SLOT(About()));
    connect(ExtiButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    //set colors
    setStyleSheet("background-color: #4c69f6;border:2px solid #007de3;border-radius: 5px");
    SinglePlayerButton->setStyleSheet("background-color: #f6db35;border:2px solid #007de3;border-radius: 5px");
    TwoPlayersButton->setStyleSheet("background-color: #ffc510;border:2px solid #007de3;border-radius: 5px");
    AboutButton->setStyleSheet("background-color: #4c94f6;border:2px solid #007de3;border-radius: 5px");
    ExtiButton->setStyleSheet("background-color: #ee5454;border:2px solid #007de3;border-radius: 5px;");

}

void StartWidget::SinglePlayer()
{
    if(SinglePlayerButton->text() == "Single Player")
    {
        SinglePlayerButton->setText("Comming Soon ...");
        SinglePlayerButton->setStyleSheet("background-color: #00FF00;border:2px solid #007de3;border-radius: 5px");

        timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(SinglePlayerNormal()));
        timer->start(1000);
    }


}

void StartWidget::SinglePlayerNormal()
{
    SinglePlayerButton->setText("Single Player");
    SinglePlayerButton->setStyleSheet("background-color: #f6db35;border:2px solid #007de3;border-radius: 5px");
    timer->stop();
}

void StartWidget::TowPlayer()
{
    v->gameMood=false;

    StartStep2 *start=new StartStep2();
    start->show();
    this->close();

}

void StartWidget::About()
{
    AboutWidget *about=new AboutWidget();
    about->show();
    this->close();
}
