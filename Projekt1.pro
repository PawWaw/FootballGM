#-------------------------------------------------
#
# Project created by QtCreator 2018-02-27T23:32:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt1
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += quickcontrols2

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    subwindow.cpp \
    attacker.cpp \
    defender.cpp \
    midfielder.cpp \
    goalkeeper.cpp \
    human.cpp \
    manager.cpp \
    player.cpp \
    statistics.cpp \
    team.cpp \
    database.cpp \
    simulation.cpp \
    simulationround.cpp

HEADERS += \
        mainwindow.h \
    subwindow.h \
    attacker.h \
    defender.h \
    midfielder.h \
    goalkeeper.h \
    human.h \
    manager.h \
    player.h \
    statistics.h \
    team.h \
    stdafx.h \
    targetver.h \
    database.h \
    simulation.h \
    simulationround.h

FORMS += \
        mainwindow.ui \
    subwindow.ui

DISTFILES += \
    readme

