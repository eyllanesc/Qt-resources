/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BARITEM_H
#define BARITEM_H

#include <QColor>
#include <QObject>

class BarItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)

public:
    BarItem(QObject *parent = Q_NULLPTR);

    QColor color() const;
    void setColor(const QColor &newColor);
    qreal value() const;
    void setValue(qreal newValue);

Q_SIGNALS:
    void colorChanged();
    void valueChanged();

private:
    QColor m_color;
    qreal m_value;
};

#endif
