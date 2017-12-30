/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PIECHART_H
#define PIECHART_H

#include <QtWidgets>

class PieChart : public QWidget
{
    Q_OBJECT

public:
    PieChart(QWidget *parent = Q_NULLPTR);
    void setValue(const QString &key, int value);
    int value(const QString &key) const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawPiePice(QPainter *painter, const QRect &rect, int pos, int value);
    void drawLegendEntry(QPainter *painter, int pos, const QRect &r, const QString &text);
    QColor colorAt(int pos) const;
    void updateTotal();
    QGradient gradient(const QRect &rect, const QColor &color) const;

private:
    QStringList m_colorNames;
    QHash<QString, int> values;
    int m_total;
    int m_lastAngleOffset;
};

#endif // PIECHART_H
