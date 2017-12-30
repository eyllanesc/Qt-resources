#include "backgroundpainter.h"
#include <QQuickWindow>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QDebug>

BackgroundPainter::BackgroundPainter(QQuickWindow *window, QObject *parent) : QObject(parent),
    m_window(window),
    m_xRot(0),
    m_yRot(0),
    m_zRot(0),
    m_xDisplacement(0),
    m_worldPos(0.0f),
    m_program(0),
    m_scale(10)
{
    connect(m_window, &QQuickWindow::openglContextCreated, this, &BackgroundPainter::initialize, Qt::DirectConnection);
    connect(m_window, &QQuickWindow::beforeRendering, this, &BackgroundPainter::paint, Qt::DirectConnection);

}

BackgroundPainter::~BackgroundPainter()
{
    m_vao.destroy();
    m_modelVbo.destroy();
    m_textureVbo.destroy();
    delete m_program;
    m_program = 0;

}

void BackgroundPainter::setScale(float scale)
{
    m_scale += scale;
    if (m_scale < 10)
        m_scale = 10;
    m_window->update();
}

void BackgroundPainter::initialize(QOpenGLContext *context)
{
    context->makeCurrent(m_window);
    initializeOpenGLFunctions();

    // Load .png image
    m_texture = new QOpenGLTexture(QImage(":/images/lady.png"));

    // Set nearest filtering mode for texture minification
    m_texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    m_texture->setWrapMode(QOpenGLTexture::Repeat);

    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment.glsl");
    m_program->bindAttributeLocation("vertex", 0);
    m_program->bindAttributeLocation("normal", 1);
    m_program->bindAttributeLocation("a_texcoord", 2);
    m_program->link();

    m_program->bind();
    m_projMatrixLoc = m_program->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
    m_lightPosLoc = m_program->uniformLocation("lightPos");

    // Create a vertex array object. In OpenGL ES 2.0 and OpenGL 2.x
    // implementations this is optional and support may not be present
    // at all. Nonetheless the below code works in all cases and makes
    // sure there is a VAO when one is needed.
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    // Setup our vertex buffer object.
    m_modelVbo.create();
    m_modelVbo.bind();
    m_modelVbo.allocate(m_object.constData(), m_object.count() * sizeof(GLfloat));

    m_textureVbo.create();
    m_textureVbo.bind();
    m_textureVbo.allocate(m_object.constTextureData(), m_object.textureCoordinateCount() * sizeof(GLfloat));

    // Store the vertex attribute bindings for the program.
    setupVertexAttribs();

    // Our camera never changes in this example.
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -1);

    // Light position is fixed.
    m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 20, 70));
    m_program->release();

    m_proj.setToIdentity();
    m_proj.ortho(-1, 1, -1, 1, -1, 100);

    context->doneCurrent();
}

void BackgroundPainter::setupVertexAttribs()
{
    m_modelVbo.bind();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    m_modelVbo.release();

    m_textureVbo.bind();
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
    m_textureVbo.release();
}

void BackgroundPainter::paint()
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    m_world.setToIdentity();
    m_world.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
    m_world.rotate(m_yRot / 16.0f, 0, 1, 0);
    m_world.rotate(m_zRot / 16.0f, 0, 0, 1);
    m_world.translate(-1, -1, 0);
    m_world.scale(m_scale);

    m_world.translate(m_worldPos, 0, 0);

    m_texture->bind();

    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    m_program->bind();
    m_program->setUniformValue(m_projMatrixLoc, m_proj);
    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);

    glDrawArrays(GL_TRIANGLES, 0, m_object.modelVertexCount());

    m_program->release();
}
