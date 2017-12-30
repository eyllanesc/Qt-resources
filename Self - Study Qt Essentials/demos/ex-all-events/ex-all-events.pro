HEADERS   = widget.h \
    eventlogwindow.h
SOURCES   = main.cpp \
            widget.cpp \
    eventlogwindow.cpp
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
