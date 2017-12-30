HEADERS= \ 
    blobwidget.h \
    mywidget.h
SOURCES= main.cpp \
    blobwidget.cpp \
    mywidget.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
