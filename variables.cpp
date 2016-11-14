#include "variables.h"

Variables::Variables()
{

    //initialize arry
    for(int i=0;i<14;i++)
        for(int j=0;j<7;j++)
            arry[i][j]= -1;

    for(int i=0;i<3;i++)
        Xplace[i]=0;

    //initialize variables
    winner =-1;
    gameMood=false;
    LastPlaceXPlayer1 = 0 ;
    LastPlaceXPlayer2 = 0 ;
    PlayerName[0]= QString("FONQRI");
    PlayerName[1]= QString("Player1");
    PlayerName[2]= QString("Player2");
    //set turn pixmap
    turnIcon->setPixmap(QPixmap(":/images/turn.png"));


}
