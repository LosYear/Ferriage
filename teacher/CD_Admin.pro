#-------------------------------------------------
#
# Project created by QtCreator 2011-06-24T18:04:25
#
#-------------------------------------------------

QT       += core gui

TARGET = CD_Admin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ldir.cpp \
    edits.cpp \
    functions.cpp \
    libs/quazip/zip.c \
    libs/quazip/unzip.c \
    libs/quazip/quazipnewinfo.cpp \
    libs/quazip/quazipfile.cpp \
    libs/quazip/quazip.cpp \
    libs/quazip/quacrc32.cpp \
    libs/quazip/quaadler32.cpp \
    libs/quazip/qioapi.cpp \
    libs/quazip/JlCompress.cpp

HEADERS  += mainwindow.h \
    ldir.h \
    edits.h \
    libs/qzipwriter_p.h \
    libs/qzipreader_p.h \
    libs/quazip/zip.h \
    libs/quazip/unzip.h \
    libs/quazip/quazipnewinfo.h \
    libs/quazip/quazipfileinfo.h \
    libs/quazip/quazipfile.h \
    libs/quazip/quazip_global.h \
    libs/quazip/quazip.h \
    libs/quazip/quacrc32.h \
    libs/quazip/quachecksum32.h \
    libs/quazip/quaadler32.h \
    libs/quazip/JlCompress.h \
    libs/quazip/ioapi.h \
    libs/quazip/crypt.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    libs/quazip/quazip.pro \
    libs/quazip/quazip.pri
