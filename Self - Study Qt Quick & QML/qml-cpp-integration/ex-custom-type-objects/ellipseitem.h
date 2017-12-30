/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QQuickPaintedItem>
#include "style.h"

class EllipseItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Style *style READ style WRITE setStyle NOTIFY styleChanged)

public:
    EllipseItem(QQuickItem *parent = Q_NULLPTR);
    void paint(QPainter *painter) Q_DECL_OVERRIDE;

    Style *style() const;
    void setStyle(Style *newStyle);

signals:
    void styleChanged();

private:
    Style *m_style;
};

#endif
