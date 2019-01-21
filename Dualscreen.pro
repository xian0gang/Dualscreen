#-------------------------------------------------
#
# Project created by QtCreator 2018-08-01T13:50:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dualscreen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    doublescreen.cpp \
    showpiclab.cpp

HEADERS  += mainwindow.h \
    form.h \
    doublescreen.h \
    showpiclab.h

FORMS    += mainwindow.ui \
    form.ui \
    doublescreen.ui
