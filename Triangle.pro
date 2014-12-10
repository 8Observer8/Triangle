#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T08:15:15
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Triangle
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp

HEADERS  += Dialog.h \
    Scene.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc
