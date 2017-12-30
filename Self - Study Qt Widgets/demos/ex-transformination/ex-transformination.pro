TEMPLATE += app
HEADERS += coordinatesystem.h \
    mainwindow.h \
    transformdialog.h \
    transformationitem.h \
    animationqueue.h
SOURCES += main.cpp \
    coordinatesystem.cpp \
    mainwindow.cpp \
    transformdialog.cpp \
    transformationitem.cpp \
    animationqueue.cpp
FORMS += mainwindow.ui \
    transformdialog.ui
RESOURCES += icons.qrc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
