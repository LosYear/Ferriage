#-------------------------------------------------
#
# Project created by QtCreator 2012-03-24T11:43:17
#
#-------------------------------------------------

QT       += core gui

TARGET = client
TEMPLATE = app

#LIBS += quazip.dll
CONFIG += link_prl
INCLUDEPATH += qjson/src \
               qjson/include

LIBS += qjson0.dll


SOURCES += main.cpp\
        mainwindow.cpp \
    qsprite.cpp \
    qraft.cpp \
    qmanager.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    qsprite.h \
    qraft.h \
    qmanager.h \
    about.h

FORMS    += mainwindow.ui \
    about.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    TODO.txt

VERSION = 0.2.0
win32:RC_FILE += windows.rc
