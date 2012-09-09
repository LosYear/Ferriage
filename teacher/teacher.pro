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
    qcommandlinkbuttonextended.cpp \
    qrule.cpp \
    qdroplabel.cpp \
    qdisplayrule.cpp \
    qdraglabel.cpp \
    qsprite.cpp \
    qraft.cpp \
    spritedialog.cpp

HEADERS  += mainwindow.h \
    qmanager.h \
    info.h \
    addclassdialog.h \
    qclass.h \
    qcommandlinkbuttonextended.h \
    qrule.h \
    qdroplabel.h \
    qdisplayrule.h \
    qdraglabel.h \
    qsprite.h \
    qraft.h \
    spritedialog.h

FORMS    += mainwindow.ui \
    info.ui \
    addclassdialog.ui \
    spritedialog.ui

INCLUDEPATH += qjson/src \
               qjson/include

LIBS += qjson0.dll

RESOURCES += \
    res.qrc

OTHER_FILES += \
    TODO.txt
