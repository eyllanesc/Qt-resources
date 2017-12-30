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

private:
    QColor colorAt(int pos) const;

private:
    QStringList m_colorNames;
    QHash<QString, int> m_values;
};

#endif // PIECHART_H
