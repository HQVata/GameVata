#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T22:22:58
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = Client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    gameclient.cpp \
    consoleui.cpp \
    stdinreader.cpp

HEADERS += \
    gameclient.h \
    consoleui.h \
    stdinreader.h
