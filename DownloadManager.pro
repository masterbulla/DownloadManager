QT += core
QT += network
QT += gui
QT += widgets

CONFIG += c++11

TARGET = DownloadManager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    downloadmanager.cpp \
    downloaderwindow.cpp

HEADERS += \
    downloadmanager.h \
    downloaderwindow.h

FORMS += \
    downloaderwindow.ui
