/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QGraphicsSceneDragDropEvent>
#include <QtCore/QMimeData>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtGui/QCursor>

#include <QtCore/QDebug>

#include <cmath>
#include <cassert>

#include "diagramitem.h"


static const double TWO_PI = 2*3.14159;

DiagramItem::DiagramItem(const QRectF& r)
    : QGraphicsPolygonItem(r)
{
    init();
}

DiagramItem::DiagramItem(const QPolygonF &p)
    : QGraphicsPolygonItem(p)
{
    init();
}

void DiagramItem::init()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag( QGraphicsItem::ItemIsSelectable);
    setFlag( QGraphicsItem::ItemIsFocusable);
    setAcceptHoverEvents(true);
    setAcceptDrops(true);
}

/*! Computes a QPainterPath that represents
 * the edge of this polygon.
 */
QPainterPath DiagramItem::outline() const
{
    QPainterPath p = shape();
    p.setFillRule(Qt::OddEvenFill);
    QTransform t;
    t.scale(.8, .8);
    p.addPolygon(t.map(p.toFillPolygon()));
    return p;
}

static QPolygonF make_regular_polygon(int n)
{
    QPolygonF poly;
    for (int i = 0; i < n; ++i) {
        poly  << QPointF(std::sin( static_cast<double>(i)*TWO_PI/static_cast<double>(n))*50,
                         std::cos( static_cast<double>(i)*TWO_PI/static_cast<double>(n))*50.);
    }
    return poly;
}

/*! Reimplemented to show a different cursor on the edge
 * on the polygon.
 */
void DiagramItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    if (outline().contains(event->pos())) {
        setCursor(Qt::PointingHandCursor);
    } else {
        unsetCursor();
    }
}

void DiagramItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (outline().contains( event->pos())) {
        m_pressPos = event->pos();
        m_polygon = polygon();
    }

    BASE::mousePressEvent( event );
}

void DiagramItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (!m_pressPos.isNull()) {
        QPointF epos = event->pos();
        QTransform t;
        t.scale(std::abs(epos.x()/m_pressPos.x()),
                std::abs(epos.y()/m_pressPos.y()));
        setPolygon(t.map(m_polygon));
    } else {
        BASE::mouseMoveEvent(event);
    }
}

void DiagramItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressPos = QPointF(); // Null point
    BASE::mouseReleaseEvent(event);
}


void DiagramItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasColor())
        event->acceptProposedAction();
}
void DiagramItem::dropEvent(QGraphicsSceneDragDropEvent* event)
{
    if ( event->mimeData()->hasColor() ) {
        setBrush(event->mimeData()->colorData().value<QColor>());
        event->acceptProposedAction();
    }
}


DiagramItem *DiagramItem::createItem(int type)
{
    DiagramItem *item = 0;
    switch( type ) {
    case TYPE_BOX:
        item = new DiagramItem(QRectF(-50,-50,100,100));
        break;
    case TYPE_TRIANGLE:
        item = new DiagramItem(QPolygonF()
                                << QPointF(0,-50)
                                << QPointF(50, 50)
                                << QPointF(-50, 50));
        break;
    case TYPE_PENTAGON:
        item = new DiagramItem(make_regular_polygon(5));
        break;
    case TYPE_ELLIPSE: {
        item = new DiagramItem(make_regular_polygon(100));
        break;
    }
    default:
        assert(0);
    }
    return item;
}

