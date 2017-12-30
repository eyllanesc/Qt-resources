#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QQuickItem>

QT_FORWARD_DECLARE_CLASS(QSGTexture)

class CustomItem : public QQuickItem
{
    Q_OBJECT
public:
    CustomItem(QQuickItem *parent = 0);
     ~CustomItem();

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

private:
    //QSGGeometry m_geometry;
    QSGTexture *m_texture;

};

#endif // CUSTOMITEM_H
