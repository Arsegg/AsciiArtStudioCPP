#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T19:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AsciiArtStudioCPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    util.cpp

HEADERS  += mainwindow.h \
    util.h

FORMS    += mainwindow.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv
