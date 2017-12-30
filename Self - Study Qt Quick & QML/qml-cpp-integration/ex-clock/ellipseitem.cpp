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
    if (m_style == Outline) {
        painter->setPen(m_color);
        painter->setBrush(Qt::NoBrush);
        
        const qreal halfPenWidth = qMax(painter->pen().width() / 2.0, 1.0);
        rect.adjust(halfPenWidth, halfPenWidth, -halfPenWidth, -halfPenWidth);
    } else {
        painter->setPen(Qt::NoPen);
        painter->setBrush(m_color);
    }
    painter->drawEllipse(rect);
    painter->restore();
}

QColor EllipseItem::color() const
{
    return m_color;
}

void EllipseItem::setColor(const QColor &newColor)
{
    if (m_color != newColor) {
        m_color = newColor;
        update();
        Q_EMIT colorChanged();
    }
}

EllipseItem::Style EllipseItem::style() const
{
    return m_style;
}

void EllipseItem::setStyle(const Style &newStyle)
{
    if (m_style != newStyle) {
        m_style = newStyle;
        update();
        Q_EMIT styleChanged();
    }
}
