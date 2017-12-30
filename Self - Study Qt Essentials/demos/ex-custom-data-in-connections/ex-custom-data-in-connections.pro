TEMPLATE = app
SOURCES= main.cpp \
    data.cpp \
    sender.cpp \
    receiver.cpp \
    simpleqobject.cpp

HEADERS += \
    data.h \
    sender.h \
    receiver.h \
    simpleqobject.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
