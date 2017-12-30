/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "baritem.h"
#include "chartitem.h"

ChartItem::ChartItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void ChartItem::paint(QPainter *painter)
{
    if (m_bars.count() == 0)
        return;

    qreal minimum = m_bars[0]->value();
    qreal maximum = minimum;

    for (int i = 1; i < m_bars.count(); ++i) {
        minimum = qMin(minimum, m_bars[i]->value());
        maximum = qMax(maximum, m_bars[i]->value());
    }

    if (maximum == minimum)
        return;

    painter->save();

    const QRectF rect = boundingRect();
    
    qreal scale = rect.height()/(maximum - minimum);
    qreal barWidth = rect.width()/m_bars.count();

    for (int i = 0; i < m_bars.count(); ++i) {
        BarItem *bar = m_bars[i];
        qreal barEdge1 = scale * (maximum - bar->value());
        qreal barEdge2 = scale * maximum;
        QRectF barRect(rect.x() + i * barWidth,
                       rect.y() + qMin(barEdge1, barEdge2),
                       barWidth, qAbs(barEdge1 - barEdge2));

        painter->setBrush(bar->color());
        painter->drawRect(barRect);
    }

    painter->restore();
}

QQmlListProperty<BarItem> ChartItem::bars()
{
    return QQmlListProperty<BarItem>(this, 0, &ChartItem::append_bar, 0, 0, 0);
}

void ChartItem::append_bar(QQmlListProperty<BarItem> *list, BarItem *bar)
{
    ChartItem *chart = qobject_cast<ChartItem *>(list->object);
    if (chart) {
        bar->setParent(chart);
        chart->m_bars.append(bar);
        chart->barsChanged();
    }
}
