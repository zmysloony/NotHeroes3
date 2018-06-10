TEMPLATE = app
TARGET = NotHeroes
CONFIG+=c++11
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    menu.cpp \
    units.cpp

HEADERS += \
    menu.h
