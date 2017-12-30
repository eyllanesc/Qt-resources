/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CHARTITEM_H
#define CHARTITEM_H

#include <QQuickPaintedItem>

class BarItem;

class ChartItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<BarItem> bars READ bars NOTIFY barsChanged)

public:
    ChartItem(QQuickItem *parent = Q_NULLPTR);
    void paint(QPainter *painter) Q_DECL_OVERRIDE;

    QQmlListProperty<BarItem> bars();

Q_SIGNALS:
    void barsChanged();

private:
    static void append_bar(QQmlListProperty<BarItem> *list, BarItem *bar);
    QList<BarItem*> m_bars;
};

#endif
