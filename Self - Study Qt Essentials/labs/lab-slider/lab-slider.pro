HEADERS= slider.h
SOURCES= main.cpp slider.cpp

OTHER_FILES += \
    readme.txt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
