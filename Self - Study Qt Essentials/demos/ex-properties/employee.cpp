/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "employee.h"

Employee::Employee() :
    Employee("NN", 0.0)
{
}

Employee::Employee(const QString &name, const float salary)
{
    m_name = name;
    m_salary = salary;
}

const QString &Employee::name() const
{
    return m_name;
}

void Employee::setName(const QString &name)
{
    if (name != m_name)
        m_name = name;
}

float Employee::salary() const
{
    return m_salary;
}

void Employee::setSalary(float &salary)
{
    if (salary != m_salary)
        m_salary = salary;
}
