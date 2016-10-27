#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T17:13:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

#QMAKE_CXXFLAGS += -std=c++11

TARGET = csvCalculator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    csvreader.cpp \
    calculator.cpp

HEADERS += \
    calculator.h \
    csvreader.h
