QT       += quick
HEADERS   = ellipseitem.h
RESOURCES = ex-custom-types.qrc
SOURCES   = main.cpp ellipseitem.cpp

# These next three lines makes the QML files show up in a section of their
# own in Qt Creator.
qml.files += $$files(*.qml)
qml.path = "."
INSTALLS += qml
