/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QMetaType>

class Employee
{
public:
    Employee();
    Employee(const QString &name, const float salary);

    bool operator !=(const Employee &employee) const
    {
        if ((employee.m_name != m_name) || (employee.m_salary != m_salary))
            return true;
        else
            return false;
    }

    const QString &name() const;
    void setName(const QString &name);

    float salary() const;
    void setSalary(float &salary);

private:
    QString m_name;
    float m_salary;
};

Q_DECLARE_METATYPE(Employee)



#endif // EMPLOYEE_H
