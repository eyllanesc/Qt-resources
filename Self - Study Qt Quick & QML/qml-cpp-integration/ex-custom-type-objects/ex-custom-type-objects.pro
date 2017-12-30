QT       += quick
HEADERS   = ellipseitem.h style.h
RESOURCES = ex-custom-type-objects.qrc
SOURCES   = main.cpp ellipseitem.cpp style.cpp

# These next three lines makes the QML files show up in a section of their
# own in Qt Creator.
qml.files += $$files(*.qml)
qml.path = "."
INSTALLS += qml

