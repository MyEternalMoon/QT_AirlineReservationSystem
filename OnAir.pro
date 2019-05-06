#-------------------------------------------------
#
# Project created by QtCreator 2019-03-29T16:08:48
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnAir
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    airlines.cpp \
    logindialog_noncustom.cpp \
    mainwindow_noncustom.cpp \
    logindialog_register_and_login.cpp \
    commonfunctions.cpp \
    airlinewidget.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    airlines.h \
    commonfunctions.h \
    airlinewidget.h


FORMS += \
        mainwindow.ui \
    logindialog.ui \
    airlineinfowidget.ui \
    airlinewidget.ui

RESOURCES += \
    Resources/buttons.qrc