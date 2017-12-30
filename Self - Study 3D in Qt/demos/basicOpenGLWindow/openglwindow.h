#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWindow>

class OpenGLWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    OpenGLWindow(QOpenGLWindow *parent = 0) {
        QSurfaceFormat format;
        format.setAlphaBufferSize(8);
        format.setMajorVersion(4);
        format.setMinorVersion(3);
        format.setSamples(8);
        format.setSwapInterval(10);
        setFormat(format);
    }

    ~OpenGLWindow();

protected:
    void initializeGL() Q_DECL_OVERRIDE { }
    void paintGL() Q_DECL_OVERRIDE { }
    void resizeGL(int, int) Q_DECL_OVERRIDE { }
};

#endif // OPENGLWINDOW_H
