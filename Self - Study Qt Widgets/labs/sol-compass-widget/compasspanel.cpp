/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "compasspanel.h"
#include "compass.h"

CompassPanel::CompassPanel(QWidget *parent) :
    QWidget(parent)
{
    init();
}

void CompassPanel::init()
{
    m_direction = new QLabel("Direction: ");
    m_leftCompass = new Compass(this);
    m_rightCompass = new Compass(this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_direction);
    layout->addWidget(m_leftCompass,  1, 0);
    layout->addWidget(m_rightCompass, 1, 1);
    setLayout(layout);

    connect(m_leftCompass, SIGNAL(directionChanged(QString)), this, SLOT(updateDirection(QString)));
    connect(m_leftCompass, SIGNAL(directionChanged(Compass::Direction)), m_rightCompass, SLOT(setDirection(Compass::Direction)));
    connect(m_rightCompass, SIGNAL(directionChanged(Compass::Direction)), m_leftCompass, SLOT(setDirection(Compass::Direction)));
    m_leftCompass->setDirection(Compass::North);
    updateDirection(m_leftCompass->directionName(Compass::North));
}

void CompassPanel::updateDirection(const QString &name)
{
    m_direction->setText(QString("Direction: %1").arg(name));
}
