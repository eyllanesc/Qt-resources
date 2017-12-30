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

CornerItem::CornerItem(Qt::Corner corner, PictureItem *parent)
	: m_content(parent), m_corner(corner), m_size(8)
	, m_operation(Off)
{
	m_startRatio = 1.0;
	setParentItem(parent);
	setRect(-m_size, -m_size, m_size*2, m_size*2);
	relayout(parent->contentsRect());
    setAcceptHoverEvents(true);
}



void CornerItem::relayout(const QRect &rect)
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


void CornerItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	event->accept();

	// do the right op
	switch (event->button()) {
		case Qt::LeftButton: m_content->resetContentsRatio(); break;
		case Qt::RightButton: m_content->setRotation(0.0, Qt::ZAxis); break;
		default:                break;
	}
}

void CornerItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	event->accept();

	// do the right op
	// rotate by default, or scale if a modifier is pressed.
	m_operation = Rotate ;
	if (event->modifiers()) m_operation = Scale;

	// intial parameters
	QRect contentsRect = m_content->contentsRect();
	m_startRatio = (double)contentsRect.width() / (double)contentsRect.height();

	update();
}

void CornerItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_operation == Off)
		return;
	event->accept();

	// modify the operation using the shortcuts
	int op = m_operation;
	if (event->modifiers()) op = Scale;

	// vector relative to the centre
	QPointF v = pos() + event->pos();
	if (v.isNull())
		return;

	// do scaling
	if (op & Scale) {
		if (op & FixScale) {
			const double r = m_startRatio;
			const double D = sqrt(v.x()*v.x() + v.y()*v.y());
			const double K = sqrt(1 + 1/(r * r));
			int W = qMax((int)((2*D)/(K)), 50);
			int H = qMax((int)((2*D)/(r*K)), 40);
			m_content->resizeContents(QRect(-W / 2, -H / 2, W, H));
		} else {
			int W = qMax(2 * fabs(v.x()), 50.0); //(m_contentsRect.width() * v.x()) / oldPos.x();
			int H = qMax(2 * fabs(v.y()), 40.0); //(m_contentsRect.height() * v.y()) / oldPos.y();
			//if (W != (int)cRect.width() || H != (int)cRect.height())
				m_content->resizeContents(QRect(-W / 2, -H / 2, W, H));
		}
	}

	// do rotation
	if (op & Rotate) {
		QPointF refPos = pos();

		// set item rotation (set rotation relative to current)
		qreal refAngle = atan2(refPos.y(), refPos.x());
		qreal newAngle = atan2(v.y(), v.x());
		double dZr = 57.29577951308232 * (newAngle - refAngle); // 180 * a / M_PI
		double zr = m_content->rotation(Qt::ZAxis) + dZr;

		// snap to M_PI/4
		if (op & FixRotate) {
			int fracts = (int)((zr - 7.5) / 15.0);
			zr = (qreal)fracts * 15.0;
		}

		// apply rotation
		m_content->setRotation(zr, Qt::ZAxis);
	}
}

void CornerItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	event->accept();
	bool accepted = m_operation != Off;
	m_operation = Off;
	update();

	// clicked
	if (accepted) {
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
