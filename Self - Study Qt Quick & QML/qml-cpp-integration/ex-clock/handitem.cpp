/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "handitem.h"

#include "timer.h"

#include <QtGui>

HandItem::HandItem(QQuickItem *parent)
    : QQuickPaintedItem(parent),
      m_timer(new Timer),
      m_angle(0),
      m_type(HourHand)
{
    connect(m_timer, &Timer::timeout, this, &HandItem::advance);
}

void HandItem::paint(QPainter *painter)
{
    QRectF rect = boundingRect();

    const qreal radius = qMin(rect.width(), rect.height()) / 2.0 - 10.0;

    painter->save();

    QPen pen = painter->pen();
    const int lineWidth = (m_type == SecondHand ? 1 : 3);
    pen.setWidth(lineWidth);
    pen.setColor(m_color);
    painter->setPen(pen);

    painter->translate(rect.center().x(), rect.center().y());

    painter->rotate(m_angle - 90); // QPainter rotation 0 degrees == 3 o'clock

    const qreal lineLength = (m_type == HourHand ? radius * 0.5 : radius);
    painter->drawLine(0, 0, lineLength, 0);

    painter->restore();
}

void HandItem::setTimer(Timer *timer)
{
    if (m_timer == timer)
        return;

    if (m_timer)
        disconnect( m_timer, SIGNAL( timeout() ), this, SLOT( advance() ) );

    m_timer = timer;

    if (m_timer)
        connect( m_timer, SIGNAL( timeout() ), this, SLOT( advance() ) );

    Q_EMIT timerChanged();
}

Timer *HandItem::timer() const
{
    return m_timer;
}

void HandItem::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;

    m_color = newColor;
    update();
    Q_EMIT colorChanged(newColor);
}

QColor HandItem::color() const
{
    return m_color;
}

void HandItem::setAngle(int angle)
{
    if (m_angle == angle)
        return;

    m_angle = angle;
    update();
    Q_EMIT angleChanged(angle);
}

int HandItem::angle() const
{
    return m_angle;
}

void HandItem::setType(Type type)
{
    if (m_type == type)
        return;

    m_type = type;
    update();
    Q_EMIT typeChanged(type);
}

HandItem::Type HandItem::type() const
{
    return m_type;
}

void HandItem::advance()
{
    const int degreesPerUnit = (m_type == HourHand ? 15 : 6);

    setAngle(m_angle + degreesPerUnit);
}
