/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QtWidgets/QGraphicsPolygonItem>

class DiagramItem : public QGraphicsPolygonItem {
public:
    typedef QGraphicsPolygonItem BASE;
    enum { TYPE_BOX, TYPE_TRIANGLE, TYPE_PENTAGON, TYPE_ELLIPSE, TYPE_TEXT };

    explicit DiagramItem(const QRectF&);
    explicit DiagramItem(const QPolygonF&);
    static DiagramItem *createItem(int type);

protected:
    /*** Event handlers used for resizing the item ***/
    void hoverMoveEvent(QGraphicsSceneHoverEvent*) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent*) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) Q_DECL_OVERRIDE;

    /*** Event handlers used for DnD ***/
    void dragEnterEvent(QGraphicsSceneDragDropEvent*) Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent*) Q_DECL_OVERRIDE;

private:
    void init();
    QPainterPath outline() const;

    QPointF m_pressPos;
    QPolygonF m_polygon;
};

#endif /* DIAGRAMITEM_H */

