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
    : QWidget(parent)
{
    m_colorNames = QColor::colorNames();
}

QColor PieChart::colorAt(int pos) const
{
    pos += 13;
    return QColor(m_colorNames.at(pos % m_colorNames.count()));
}
