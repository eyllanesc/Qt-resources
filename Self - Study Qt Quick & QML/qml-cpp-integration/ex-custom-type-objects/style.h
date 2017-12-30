/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef STYLE_H
#define STYLE_H

#include <QColor>
#include <QObject>

class Style : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool filled READ filled WRITE setFilled NOTIFY filledChanged)

public:
    Style(QObject *parent = 0);

    QColor color() const;
    void setColor(const QColor &newColor);
    bool filled() const;
    void setFilled(bool newFilled);

signals:
    void colorChanged();
    void filledChanged();

private:
    QColor m_color;
    bool m_filled;
};

#endif
