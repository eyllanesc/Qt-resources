/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include <math.h>
#include "corneritem.h"
#include "pictureitem.h"

CornerItem::CornerItem(Qt::Corner corner, PictureItem* parent)
  : QGraphicsRectItem(parent), m_content(parent), m_corner(corner), m_size(8)
    , m_operation(Off)
{
    setRect(-m_size, -m_size, m_size*2, m_size*2);
    setAcceptsHoverEvents(true);
    relayout(parent->contentsRect());
    setAcceptsHoverEvents(true);
}


void CornerItem::relayout(const QRect & rect)
{
	// change size, if needed
	int size = 1 + (int)sqrt((float)qMin(rect.width(), rect.height()));
	if (size != m_size) {
		prepareGeometryChange();
		m_size = size;
	}

	// place at the right corner
	switch (m_corner) {
		case Qt::TopLeftCorner: setPos(rect.topLeft() + QPoint(m_size, m_size)); break;
		case Qt::TopRightCorner: setPos(rect.topRight() + QPoint(-m_size + 1, m_size)); break;
		case Qt::BottomLeftCorner: setPos(rect.bottomLeft() + QPoint(m_size, -m_size + 1)); break;
		case Qt::BottomRightCorner: setPos(rect.bottomRight() + QPoint(-m_size + 1, -m_size + 1)); break;
	}
}


void CornerItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * /*widget*/)
{

    QColor color = Qt::blue;
    if (option->state & QStyle::State_MouseOver) {
        if (m_operation != Off)
            color.setAlpha(250);
        else
            color.setAlpha(196);
    } else
        color.setAlpha(128);
    painter->fillRect(boundingRect(), color);
}

