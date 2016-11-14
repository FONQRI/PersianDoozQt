#pragma once
#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
class AboutWidget:public QWidget
{
    Q_OBJECT
public:
    AboutWidget(QWidget *parent=0);
private:
    QPushButton *Back;
    QLabel      *Info;

public slots:
    void back();

};

#endif // ABOUTWIDGET_H
