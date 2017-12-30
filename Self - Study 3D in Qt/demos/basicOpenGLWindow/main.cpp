#include "openglwindow.h"
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    OpenGLWindow w;
    w.show();

    return a.exec();
}
