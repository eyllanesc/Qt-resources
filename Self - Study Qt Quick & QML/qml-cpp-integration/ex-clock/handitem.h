/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef HANDITEM_H
#define HANDITEM_H

#include <QQuickPaintedItem>

class Timer;

class HandItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Timer* timer READ timer WRITE setTimer NOTIFY timerChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(double angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)

    Q_ENUMS(Type)
    Q_CLASSINFO("DefaultProperty", "timer")

public:
    enum Type {
        HourHand,
        MinuteHand,
        SecondHand
    };

    explicit HandItem(QQuickItem *parent = Q_NULLPTR);

    void paint(QPainter *painter) Q_DECL_OVERRIDE;

    void setTimer(Timer *timer);
    Timer *timer() const;

    void setColor(const QColor &newColor);
    QColor color() const;

    void setAngle(int angle);
    int angle() const;

    void setType(Type type);
    Type type() const;

public Q_SLOTS:
    void advance();

Q_SIGNALS:
    void timerChanged();
    void colorChanged(const QColor &color);
    void angleChanged(double angle);
    void typeChanged(Type type);

private:
    Timer *m_timer;
    QColor m_color;
    int m_angle;
    Type m_type;
};

#endif // HANDITEM_H
