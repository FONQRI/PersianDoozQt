#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T14:17:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DOOZ
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    variables.cpp \
    congratulations.cpp \
    startwidget.cpp \
    aboutwidget.cpp \
    player.cpp \
    startstep2.cpp

HEADERS  += \
    Game.h \
    variables.h \
    congratulations.h \
    startwidget.h \
    aboutwidget.h \
    player.h \
    startstep2.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res.qrc

