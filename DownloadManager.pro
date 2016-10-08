QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = DownloadManager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    downloadmanager.cpp \
    textprogressbar.cpp

HEADERS += \
    downloadmanager.h \
    textprogressbar.h
