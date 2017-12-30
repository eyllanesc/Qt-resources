QT += core gui widgets

TEMPLATE = app
TARGET = diagram 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += diagramitem.h diagramscene.h mainwindow.h toolbox.h
SOURCES += diagramitem.cpp diagramscene.cpp main.cpp mainwindow.cpp toolbox.cpp
