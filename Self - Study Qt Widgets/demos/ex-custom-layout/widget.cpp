/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "widget.h"
#include "customlayout.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout = new CustomLayout(0, this);

    shortButton = new QPushButton(tr("Short"));
    longerButton = new QPushButton(tr("Longer"));

    differentTextButton = new QPushButton(tr("Different text"));
    moreTextButton = new QPushButton(tr("More text"));
    evenLongerButtonTextButton = new QPushButton(tr("Even longer button text"));

    layout->addWidget(shortButton);
    layout->addWidget(longerButton);
    layout->addWidget(differentTextButton);
    layout->addWidget(moreTextButton);
    layout->addWidget(evenLongerButtonTextButton);
    setLayout(layout);
}

Widget::~Widget()
{
}

