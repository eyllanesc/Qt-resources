QT += quick widgets

SOURCES += main.cpp \
           citymodel.cpp \
           ../cityengine/cityengine.cpp

HEADERS += citymodel.h \
           ../cityengine/cityengine.h

INCLUDEPATH += ../cityengine

RESOURCES += sol-cities-standarditem.qrc \
             ../cityengine/cities.qrc

OTHER_FILES += main.qml
