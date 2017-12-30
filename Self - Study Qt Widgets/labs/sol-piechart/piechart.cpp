/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "piechart.h"

PieChart::PieChart(QWidget *parent)
    : QWidget(parent),
      m_colorNames(QColor::colorNames()),
      m_total(-1),
      m_lastAngleOffset(0)
{}

void PieChart::setValue(const QString &key, int value)
{
    values[key] = value;
    m_total = -1;
}

int PieChart::value(const QString &key) const {
    return values[key];
}

QSize PieChart::sizeHint() const {
    return minimumSizeHint();
}

QSize PieChart::minimumSizeHint() const {
    return QSize(80, 80);
    // return QSize(160,80); // with legend
}

void PieChart::paintEvent(QPaintEvent *)
{
    // update total
    updateTotal();

    // prepare painter
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);


    QRect leftRect(rect()); // 0,0,width,height
    leftRect.setRight(rect().height()); // 0.0,height,height
    //p.drawRect(leftRect);

    // dedicate right half to legend
    QRect rightRect(leftRect.topRight(), rect().bottomRight());
    rightRect.adjust(10,10,-10,-10);

    //        p.drawRect(rightRect);
    int pos = 0;

    // create an entry for every piece of the pie
    foreach(QString text, values.keys()) {
        int value = values[text];
        drawPiePice(&p, leftRect, pos, value);

        drawLegendEntry(&p, pos, rightRect, text);
        pos++;
    }
}

void PieChart::drawPiePice(QPainter *p, const QRect &r, int pos, int value)
{
    if(pos == 0) {
        m_lastAngleOffset = 0;
    }
    int angle = (int)(16*360*(value/(double)m_total));
    QColor col = colorAt(pos);
    p->setBrush(gradient(r, col));
    p->drawPie(r, m_lastAngleOffset, angle);
    m_lastAngleOffset += angle;
}

void PieChart::drawLegendEntry(QPainter *p, int pos, const QRect &r, const QString &text)
{
    int fh = fontMetrics().height();
    QRect box(0,(fh*2)*pos,fh,fh);
    box.translate(r.topLeft());
    p->setBrush(colorAt(pos));
    p->drawRect(box);
    QPoint textStart = box.topRight();
    textStart += QPoint(fontMetrics().width('x'), 0);

    QPoint textEnd(r.right(), box.bottom());
    p->drawText(QRect(textStart, textEnd), Qt::AlignVCenter, text);
}

QColor PieChart::colorAt(int pos) const
{
    pos += 13;
    return QColor(m_colorNames.at(pos%m_colorNames.count()));
}

void PieChart::updateTotal()
{
    if(m_total == -1) { // needs recalc
        int total = 0;
        foreach(int value, values) {
            total += value;
        }
        m_total = total;
    }
}

QGradient PieChart::gradient(const QRect &r, const QColor &c) const
{
    QRadialGradient gradient(r.center(), r.width(), r.topLeft());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, c);
    return gradient;
}
