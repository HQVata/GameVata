#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T23:26:22
#
#-------------------------------------------------

QT       -= gui

TARGET = Packer
TEMPLATE = lib
CONFIG += staticlib

SOURCES += packer.cpp

HEADERS += packer.h
unix {
    target.path = ~/git
    INSTALLS += target
}
