#-------------------------------------------------
#
# Project created by QtCreator 2019-12-20T17:22:30
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Course
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Sources/bullet.cpp \
        Sources/enemy.cpp \
        Sources/game.cpp \
        Sources/health.cpp \
        Sources/main.cpp \
        Sources/mainwindow.cpp \
        Sources/player.cpp \
        Sources/score.cpp \
        Sources/test_player.cpp

HEADERS += \
        Sources/bullet.h \
        Sources/enemy.h \
        Sources/game.h \
        Sources/health.h \
        Sources/mainwindow.h \
        Sources/player.h \
        Sources/score.h \
        Sources/test_player.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
