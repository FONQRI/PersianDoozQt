#pragma once
#ifndef CONGRATULATIONS_H
#define CONGRATULATIONS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QRectF>
#include <QPointF>
#include <QPushButton>

#include "startwidget.h"

#include "variables.h"
extern Variables *v;
class Congratulations:public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)
public:
    Congratulations(QWidget *parent =0);
    QPointF p(float x, float y);
private:
    QLabel *con;
    QPushButton *Back;
    QPushButton *Exit;
    StartWidget *start;
public slots:
    void back();
};

#endif // CONGRATULATIONS_H
