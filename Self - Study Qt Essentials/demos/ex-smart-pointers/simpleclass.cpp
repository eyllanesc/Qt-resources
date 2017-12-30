/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include "simpleclass.h"

SimpleClass::SimpleClass(QObject *parent) : QObject(parent)
{
}

SimpleClass::~SimpleClass()
{
    qDebug() << "SimpleClass type object destructed";
}
