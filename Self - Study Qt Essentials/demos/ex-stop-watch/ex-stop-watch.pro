HEADERS   = stopwatch.h
SOURCES   = main.cpp \
            stopwatch.cpp
TEMPLATE  = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
