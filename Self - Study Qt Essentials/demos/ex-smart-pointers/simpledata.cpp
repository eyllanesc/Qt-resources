/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "simpledata.h"
#include <QDebug>

SimpleData::SimpleData() :
    m_member(42)
{  
}

SimpleData::~SimpleData()
{
    qDebug() << "SimpleData type object destructed";
}

int SimpleData::value() const
{
    return m_member;
}

void SimpleData::setValue(int newValue)
{
    m_member = newValue;
}
