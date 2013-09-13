#-------------------------------------------------
#
# Project created by QtCreator 2013-09-12T14:09:57
#
#-------------------------------------------------

QT       -= core

QT       -= gui

TARGET = oblig1_d
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lib.cpp
LIBS += -larmadillo -lblas -llapack
