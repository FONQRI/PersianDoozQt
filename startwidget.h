#pragma once
#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

class StartWidget:public QWidget
{
    Q_OBJECT
public:
    StartWidget(QWidget *parent=0);
public slots:
    void SinglePlayer();
    void SinglePlayerNormal();
    void TowPlayer();
    void About();
private:
    QPushButton *SinglePlayerButton;
    QPushButton *TwoPlayersButton;
    QPushButton *AboutButton;
    QPushButton *ExtiButton;
    QLabel      *StartImageLabel;
    QPixmap     *Image;
    QTimer      *timer;
//    StartStep2  *start;

};

#endif // STARTWIDGET_H
