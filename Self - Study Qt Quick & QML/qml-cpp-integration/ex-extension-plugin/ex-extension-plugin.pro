TEMPLATE  = subdirs
SUBDIRS   = application \
            ellipseplugin

QMAKE_CLEAN = plugins/*
QMAKE_DISTCLEAN = plugins/*
OTHER_FILES = application/files/ellipse9.qml standalone/qmldir standalone/ellipse9s.qml
