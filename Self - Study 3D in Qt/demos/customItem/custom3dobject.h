#ifndef CUSTOM3DOBJECT_H
#define CUSTOM3DOBJECT_H

#include <qopengl.h>
#include <QVector>
#include <QVector3D>

class Custom3DObject
{
public:
    Custom3DObject();
    const GLfloat *constData() const { return m_data.constData(); }
    const GLfloat *constTextureData() const { return m_textureData.constData(); }

    int count() const { return m_count; }
    int modelCount() const { return m_modelCount; }
    int backgroundCount() const { return m_backgroundCount; }

    int textureCoordinateCount() const { return m_textureCoordinateCount; }

    int modelVertexCount() const { return m_modelCount / 6; }
    int backgroundVertexCount() const { return m_backgroundCount / 6; }

private:
    void add(const QVector3D &v, const QVector3D &n);
    void setVertexTextureCoordinates(GLfloat p1s, GLfloat p1t, GLfloat p2s, GLfloat p2t, GLfloat p3s, GLfloat p3t);

    QVector<GLfloat> m_data;
    QVector<GLfloat> m_textureData;
    int m_count;            // Vertex 3D coordinates + normals (6 values)
    int m_modelCount;       // Model vertex 3D coordinates
    int m_backgroundCount;  // Background vertex 3D coordinates
    int m_textureCoordinateCount;
};

#endif // CUSTOM3DOBJECT_H
