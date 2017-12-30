#ifndef BACKGROUNDPAINTER_H
#define BACKGROUNDPAINTER_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "custom3dobject.h"

QT_FORWARD_DECLARE_CLASS(QQuickWindow)
QT_FORWARD_DECLARE_CLASS(QOpenGLContext)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLFramebufferObject)

class BackgroundPainter : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit BackgroundPainter(QQuickWindow *window, QObject *parent = 0);
    ~BackgroundPainter();

    Q_INVOKABLE void setScale(float scale);

protected Q_SLOTS:
    void initialize(QOpenGLContext *context);
    void paint();

protected:
    void setupVertexAttribs();

private:
    QQuickWindow *m_window;

    int m_xRot;
    int m_yRot;
    int m_zRot;
    int m_xDisplacement;
    QPoint m_lastPos;
    GLfloat m_worldPos;
    QOpenGLTexture *m_texture;

    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_modelVbo;
    QOpenGLBuffer m_textureVbo;

    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;
    Custom3DObject m_object;

    float m_scale;
};

#endif // BACKGROUNDPAINTER_H
