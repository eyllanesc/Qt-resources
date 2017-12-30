TARGET = layout
TEMPLATE = app
SOURCES += main.cpp \
    widget.cpp \
    customlayout.cpp
HEADERS += widget.h \
    customlayout.h
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

