/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "compasspanel.h"

CompassPanel::CompassPanel(QWidget *parent)
    : QWidget(parent)
{
    init();
}

void CompassPanel::init()
{
    m_direction = new QLabel("Direction: ");
    m_leftCompass = new QLabel("Left Compass");
    m_rightCompass = new QLabel("Right Compass");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_direction);
    layout->addWidget(m_leftCompass, 1, 0);
    layout->addWidget(m_rightCompass, 1, 1);
    setLayout(layout);
}

void CompassPanel::updateDirection(const QString &name)
{
    m_direction->setText(QString("Direction: %1").arg(name));
}
