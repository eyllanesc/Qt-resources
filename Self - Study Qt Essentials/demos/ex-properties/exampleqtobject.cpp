/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtDebug>
#include "exampleqtobject.h"

ExampleQtObject::ExampleQtObject(QObject *parent) :
    QObject(parent),
    m_regions(Africa | Europe)
{
}

void ExampleQtObject::showEmployeeData()
{
    qDebug() << "Employee name" << m_employee.name();
    qDebug() << "Employee salary" << m_employee.salary();
    qDebug() << "Regions" << m_regions;
}

