TEMPLATE=app
SOURCES=main.cpp \
    helpfilter.cpp

HEADERS += \
    helpfilter.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
