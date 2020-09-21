#-------------------------------------------------
#
# Project created by QtCreator 2014-12-29T16:20:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PDI_TP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqgraphicsview.cpp \
    cimagen.cpp \
    qcustomplot.cpp \
    myqimage.cpp

HEADERS  += mainwindow.h \
    myqgraphicsview.h \
    cimagen.h \
    qcustomplot.h \
    myqimage.h

FORMS    += mainwindow.ui
