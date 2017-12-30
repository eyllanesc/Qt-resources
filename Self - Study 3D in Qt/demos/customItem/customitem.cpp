#include "customitem.h"
#include <QSGSimpleTextureNode>
#include <QQuickWindow>

CustomItem::CustomItem(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    setFlag(ItemHasContents, false);
    setSize(QSizeF(250, 250));
}

CustomItem::~CustomItem()
{
}

QSGNode *CustomItem::updatePaintNode(QSGNode *node, QQuickItem::UpdatePaintNodeData *updateData)
{
    Q_UNUSED(updateData);

    QSGSimpleTextureNode *textureNode = static_cast<QSGSimpleTextureNode *>(node);
    if (!textureNode) {
        textureNode = new QSGSimpleTextureNode();
        QImage image(":/images/lady.png");
        m_texture = window()->createTextureFromImage(image);
        textureNode->setTexture(m_texture);}
        textureNode->setRect(0, 0, width(), height());
        textureNode->setFiltering(QSGTexture::Linear);

    return textureNode;

}
