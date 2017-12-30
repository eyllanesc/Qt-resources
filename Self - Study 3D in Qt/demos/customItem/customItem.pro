TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    customitem.cpp \
    backgroundpainter.cpp \
    custom3dobject.cpp \
    customview.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    customitem.h \
    backgroundpainter.h \
    custom3dobject.h \
    customview.h

DISTFILES += \
    DemoItem.qml
