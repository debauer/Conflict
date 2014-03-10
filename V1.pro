#-------------------------------------------------
#
# Project created by QtCreator 2014-02-05T21:41:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = V1
TEMPLATE = app

CONFIG += c++11
QT += uitools

include(qextserialport/src/qextserialport.pri)


SOURCES += main.cpp\
        mainwindow.cpp \
    conflict_core.cpp \
    carriage.cpp \
    driver/uart.cpp \
    data/system.cpp \
    conflictwidget.cpp \
    data/dfm.cpp \
    data/kanal.cpp \
    data/data.cpp

HEADERS  += fetchThread.h \
    mainwindow.h \
    conflict_core.h \
    carriage.h \
    driver/uart.h \
    driver/absInterface.h \
    structs.h \
    data/system.h \
    conflictwidget.h \
    data/dfm.h \
    data/kanal.h \
    data/data.h


FORMS    += mainwindow.ui \
    conflictwidget.ui

OTHER_FILES +=
