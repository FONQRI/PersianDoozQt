#pragma once
#ifndef STARTSTEP2_H
#define STARTSTEP2_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <startwidget.h>
#include <QLineEdit>
#include <QLabel>
#include "variables.h"
#include "Game.h"

#include "startwidget.h"
extern Variables *v;
extern Game *game;
class StartStep2:public QWidget
{
    Q_OBJECT
public:
    StartStep2(QWidget *parent=0);

private:
    QPushButton *Back;
    QPushButton *Exit;
    QPushButton *startGame;
    QLineEdit   *player1;
    QLineEdit   *player2;
    QLabel      *player1Name;
    QLabel      *player2Name;
    StartWidget *start;
    QLabel      *error;
public slots:
    void back();
    void startgame();




};

#endif // STARTSTEP2_H
