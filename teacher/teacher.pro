#-------------------------------------------------
#
# Project created by QtCreator 2012-04-02T21:35:19
#
#-------------------------------------------------

QT       += core gui

TARGET = teacher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qmanager.cpp \
    info.cpp \
    addclassdialog.cpp \
    qclass.cpp \
    qcommandlinkbuttonextended.cpp

HEADERS  += mainwindow.h \
    qmanager.h \
    info.h \
    addclassdialog.h \
    qclass.h \
    qcommandlinkbuttonextended.h

FORMS    += mainwindow.ui \
    info.ui \
    addclassdialog.ui

INCLUDEPATH += qjson/src \
               qjson/include

LIBS += qjson0.dll

RESOURCES += \
    res.qrc
