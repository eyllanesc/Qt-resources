/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtDebug>
#include "employee.h"
#include "exampleqtobject.h"

int main(int, char *[])
{
    Employee employee("Hard-working Developer", 7200.16);
    ExampleQtObject object;
    object.setProperty("regions", ExampleQtObject::Europe | ExampleQtObject::Americas);
    object.setProperty("employee", QVariant::fromValue(employee));

    object.showEmployeeData();
}
