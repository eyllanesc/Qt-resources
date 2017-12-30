/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EXAMPLEQTOBJECT_H
#define EXAMPLEQTOBJECT_H

#include <QObject>
#include "employee.h"

class ExampleQtObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Employee employee MEMBER m_employee NOTIFY employeeChanged)
    Q_PROPERTY(Regions regions MEMBER m_regions NOTIFY regionsChanged)
public:
    explicit ExampleQtObject(QObject *parent = 0);

    enum Region { Africa = 0x01, Americas = 0x02, Asia = 0x04, Australia = 0x08, Europe = 0x10 };
    Q_DECLARE_FLAGS(Regions, Region)
    Q_FLAG(Region) // Q_FLAG registers the enumeration using Q_ENUM

Q_SIGNALS:
    void employeeChanged();
    void regionsChanged();

public Q_SLOTS:
    void showEmployeeData();

private:
    Employee m_employee;
    Regions m_regions;
};

#endif // EXAMPLEQTOBJECT_H
