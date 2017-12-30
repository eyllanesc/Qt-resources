/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "simpleqobject.h"

SimpleQObject::SimpleQObject(QObject *parent) :
    QObject(parent),
    m_integer(42),
    m_data(Data(10, &m_integer, QString("Hello World")))
{
}
