#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T10:51:37
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bysykler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        jsonrequest.cpp \
    citybikeswidget.cpp

HEADERS  += mainwindow.h \
        jsonrequest.h \
    citybikeswidget.h

FORMS    +=

OTHER_FILES += \
    2012eid.json
