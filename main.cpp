#include <QApplication>

#include "Game.h"
#include "variables.h"
#include "startwidget.h"
//#include "startstep2.h"
//creat global Game for using in other classes
Game *game;
//creat a global variable class for keeping global variables
Variables *v;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    v=new Variables();
    game=new Game();
    //start window
    StartWidget *start=new StartWidget();
    start->show();
//    StartStep2 *s=new StartStep2();
//    s->show();



    QCoreApplication::quit();
    return a.exec();
}
