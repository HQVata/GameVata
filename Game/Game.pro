#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T11:37:29
#
#-------------------------------------------------

QT       -= gui

TARGET = Game
TEMPLATE = lib
CONFIG += staticlib

SOURCES += game.cpp

HEADERS += game.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
