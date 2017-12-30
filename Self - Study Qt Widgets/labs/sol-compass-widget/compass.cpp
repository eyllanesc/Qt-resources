/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "compass.h"

Compass::Compass(QWidget *parent)
    : QWidget(parent)
{
    init();
    setDirection(North);
}

Compass::Compass(Direction d, QWidget *parent)
    : QWidget(parent)
{
    init();
    setDirection(d);
}

void Compass::init()
{
    m_directionMap.insert(North, "North");
    m_directionMap.insert(South, "South");
    m_directionMap.insert(West, "West");
    m_directionMap.insert(East, "East");

    m_group = new QButtonGroup(this);
    m_group->setExclusive(true);

    connect(m_group, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &Compass::buttonClicked);
    QGridLayout *layout = new QGridLayout(this);

    QPushButton *north = new QPushButton(tr("North"));
    north->setCheckable(true);
    m_group->addButton(north, North);
    layout->addWidget(north, 0, 1);

    QPushButton *south = new QPushButton(tr("South"));
    south->setCheckable(true);
    m_group->addButton(south, South);
    layout->addWidget(south, 2, 1);

    QPushButton *east = new QPushButton(tr("East"));
    east->setCheckable(true);
    m_group->addButton(east, East);
    layout->addWidget(east, 1, 2);

    QPushButton *west = new QPushButton(tr("West"));
    west->setCheckable(true);
    m_group->addButton(west, West);
    layout->addWidget(west, 1, 0);
}

Compass::Direction Compass::direction() const
{
    return m_direction;
}

void Compass::setDirection(Direction d)
{
    if(d == m_direction) {
        return;
    }
    m_direction = d;
    QAbstractButton *button = m_group->button((int)d);
    if(button) {
        button->setChecked(true);
    }
    buttonClicked((int)d);
}

void Compass::buttonClicked(int id)
{
    Direction d = (Direction) id;
    emit directionChanged(d);
    emit directionChanged(m_directionMap[d]);
}

QString Compass::directionName(Direction d) const
{
    return m_directionMap[d];
}
