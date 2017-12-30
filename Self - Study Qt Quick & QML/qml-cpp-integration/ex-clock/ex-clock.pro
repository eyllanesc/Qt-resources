QT += quick

CONFIG += debug

SOURCES += main.cpp \
           timer.cpp \
           ellipseitem.cpp \
           intervalsettings.cpp \
    handitem.cpp

HEADERS += timer.h \
           ellipseitem.h \
           intervalsettings.h \
    handitem.h

RESOURCES += ex-clock.qrc

OTHER_FILES += \
    main.qml
