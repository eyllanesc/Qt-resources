/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "ellipseitem.h"

EllipseItem::EllipseItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void EllipseItem::paint(QPainter *painter)
{
    QRectF rect = boundingRect();
  
    painter->save();
    if (!m_style->filled()) {
        painter->setPen(m_style->color());
        painter->setBrush(Qt::NoBrush);
        
        const qreal halfPenWidth = qMax(painter->pen().width() / 2.0, 1.0);
        rect.adjust(halfPenWidth, halfPenWidth, -halfPenWidth, -halfPenWidth);
    } else {
        painter->setPen(Qt::NoPen);
        painter->setBrush(m_style->color());
    }
    painter->drawEllipse(rect);
    painter->restore();
}

Style *EllipseItem::style() const
{
    return m_style;
}

void EllipseItem::setStyle(Style *newStyle)
{
    if (m_style != newStyle) {
        m_style = newStyle;
        m_style->setParent(this);
        emit styleChanged();
        update();
    }
}
