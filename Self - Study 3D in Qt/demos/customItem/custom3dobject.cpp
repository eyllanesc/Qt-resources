#include "custom3dobject.h"
#include <qmath.h>

Custom3DObject::Custom3DObject()
    : m_count(0),
      m_modelCount(0),
      m_backgroundCount(0),
      m_textureCoordinateCount(0)
{
    m_data.resize(30 * 6);
    m_textureData.resize(30 * 2);

    QVector3D v(0.0f, 0.0f, -0.05f);
    QVector3D n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, -1.0f, 0.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.0f, 0.3f, -0.05f);
        else if(i==1)
            v=QVector3D(0.2f, 0.0f, -0.05f);
    }
    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f);

    // Face other triangle
    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.0f, 0.3f, -0.05f);
        else if(i==1)
            v=QVector3D(0.2f, 0.3f, -0.05f);
    }

    setVertexTextureCoordinates(0.5f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f);

    // Back
    v = QVector3D(0.0f, 0.0f, 0.05f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.2f, 0.0f, 0.05f);
        else if(i==1)
            v=QVector3D(0.0f, 0.3f, 0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Back other triangle
    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.2f, 0.0f, 0.05f);
        else if(i==1)
            v=QVector3D(0.2f, 0.3f, 0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Top
    v = QVector3D(0.0f, 0.0f, -0.05f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.2f, 0.0f, -0.05f);
        else if(i==1)
            v=QVector3D(0.2f, 0.0f, 0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Top other triangle
    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.0f, 0.0f, 0.05f);
        else if(i==1)
            v=QVector3D(0.0f, 0.0f, -0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Bottom
    v = QVector3D(0.2f, 0.3f, -0.05f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, -1.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.0f, 0.3f, -0.05f);
        else if(i==1)
            v=QVector3D(0.0f, 0.3f, 0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Bottom other triangle
    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.2f, 0.3f, 0.05f);
        else if(i==1)
            v=QVector3D(0.2f, 0.3f, -0.05f);
    }

    setVertexTextureCoordinates(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    m_modelCount = m_count;

    // Background
    v= QVector3D(-0.2f, -0.2f, 0.2f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, -1.0f, 0.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(-0.2f, 0.5f, 0.2f);
        else if(i==1)
            v=QVector3D(0.4f, 0.5f, 0.2f);
    }

    setVertexTextureCoordinates(0.5f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f);

    // Background other triangle
    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.4f, -0.2f, 0.2f);
        else if(i==1)
            v=QVector3D(-0.2f, -0.2f, 0.2f);
    }

    setVertexTextureCoordinates(1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.0f);

    // Background bottom
    v = QVector3D(-0.2f, 0.5f, 0.2f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(-0.2f, 0.5f, -0.1f);
        else if(i==1)
            v=QVector3D(0.4f, 0.5f, -0.1f);
    }

    setVertexTextureCoordinates(0.5f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f);

    // Background bottom other triangle
    v = QVector3D(-0.2f, 0.5f, 0.2f);
    n = QVector3D::normal(QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f));

    for (int i=0; i<3; ++i) {
        add(v, n);
        if (i==0)
            v=QVector3D(0.4f, 0.5f, -0.1f);
        else if(i==1)
            v=QVector3D(0.4f, 0.5f, 0.2f);
    }

    setVertexTextureCoordinates(0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f);

    m_backgroundCount = m_count - m_modelCount;
}

void Custom3DObject::add(const QVector3D &v, const QVector3D &n)
{
    GLfloat *p = m_data.data() + m_count;
    *p++ = v.x();
    *p++ = v.y();
    *p++ = v.z();
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    m_count += 6;
}

void Custom3DObject::setVertexTextureCoordinates(GLfloat p1s, GLfloat p1t, GLfloat p2s, GLfloat p2t, GLfloat p3s, GLfloat p3t)
{
    GLfloat *p = m_textureData.data() + m_textureCoordinateCount;
    *p++ = p1s;
    ++m_textureCoordinateCount;
    *p++ = p1t;
    ++m_textureCoordinateCount;

    *p++ = p2s;
    ++m_textureCoordinateCount;
    *p++ = p2t;
    ++m_textureCoordinateCount;

    *p++ = p3s;
    ++m_textureCoordinateCount;
    *p++ = p3t;
    ++m_textureCoordinateCount;
}
