#-------------------------------------------------
#
# Project created by QtCreator 2012-07-16T20:19:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qsprite.cpp \
    qrule.cpp \
    qraft.cpp \
    qmanager.cpp \
    qclass.cpp \
    qdeletearea.cpp

HEADERS  += mainwindow.h \
    qsprite.h \
    qrule.h \
    qraft.h \
    qmanager.h \
    qclass.h \
    qdeletearea.h

INCLUDEPATH += qjson/src \
               qjson/include

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

LIBS += qjson0.dll
