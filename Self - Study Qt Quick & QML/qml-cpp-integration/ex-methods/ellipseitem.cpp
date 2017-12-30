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
    QTimer::singleShot(2000, this, SIGNAL(ready()));
    qsrand(QDateTime::currentDateTime().toTime_t());
}

void EllipseItem::paint(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_color);
    painter->drawEllipse(boundingRect());
    painter->restore();
}

const QColor EllipseItem::color() const
{
    return m_color;
}

void EllipseItem::setColor(const QColor &newColor)
{
    if (m_color != newColor) {
        m_color = newColor;
        update();
        emit colorChanged();
    }
}

QColor EllipseItem::randomColor() const
{
    return QColor(qrand() & 0xff, qrand() & 0xff, qrand() & 0xff);
}
