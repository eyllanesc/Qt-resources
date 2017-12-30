TEMPLATE = app
QT       += quick network widgets
HEADERS += tcpconnectionelement.h runtype.h
SOURCES += main.cpp tcpconnectionelement.cpp runtype.cpp
RESOURCES +=  resources.qrc
FORMS += runtype.ui

# These next three lines makes the QML files show up in a section of their
# own in Qt Creator.
OTHER_FILES += $$files(*.qml)
