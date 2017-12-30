QT       += quick
HEADERS   = triangleitem.h
RESOURCES = ex-simple-item-scenegraph.qrc
SOURCES   = main.cpp triangleitem.cpp

# These next three lines makes the QML files show up in a section of their
# own in Qt Creator.
qml.files += $$files(*.qml)
qml.path = "."
INSTALLS += qml
