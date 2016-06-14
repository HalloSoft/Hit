#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T04:47:05
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets widgets

CONFIG += c++11

TARGET = Hit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    livedisplaywidget.cpp \
    aboutbox.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    livedisplaywidget.h \
    aboutbox.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    livedisplaywidget.ui \
    aboutbox.ui \
    settingsdialog.ui

RESOURCES += \
    resources.qrc

VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_REVISION = 0
VERSION_BUILD = 5
DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
           "VERSION_MINOR=$$VERSION_MINOR"\
           "VERSION_REVISION=$$VERSION_REVISION"\
           "VERSION_BUILD=$$VERSION_BUILD"
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_REVISION}.$${VERSION_BUILD}
