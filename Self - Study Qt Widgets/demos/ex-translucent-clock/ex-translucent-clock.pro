QT +=
HEADERS       = clock.h
SOURCES       = clock.cpp \
                main.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/widgets/translucent
#sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS translucent.pro
#sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/translucent
#INSTALLS += target sources
