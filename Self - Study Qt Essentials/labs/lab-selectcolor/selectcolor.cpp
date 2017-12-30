/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "selectcolor.h"

SelectColor::SelectColor(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel("white");
    m_label->setAutoFillBackground(true);
    QPushButton *button = new QPushButton("Select Color");

    QVBoxLayout *col = new QVBoxLayout;
    QHBoxLayout *row = new QHBoxLayout;
    row->addWidget(new QLabel("Color is: "));
    row->addWidget(m_label);
    col->addLayout(row);
    col->addWidget(button);

    setLayout(col);
}
