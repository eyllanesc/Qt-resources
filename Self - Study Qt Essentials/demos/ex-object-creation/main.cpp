/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QObject>
#include <QString>
#include <QPointer>
#include <QDebug>

// Do not define function arguments as QPointers
// Conversion is automatic
void simpleFunction(QObject *object, const QString &string)
{
    Q_UNUSED(object)
    // This string would share the same data with argument string
    QString stringCopy(string);

    // Changing the string results the original string data to be copied
    stringCopy.append(", am I not");
    qDebug() << "Copied string" << stringCopy;
}

int main(int, char *[])
{
    // Parent Qt object is allocated in the stack,
    // as it exists as long we stay in main()
    QObject parentObject;

    // Value type allocated in the stack
    QString string("I'm a string");

    // Children are deleted
    // Cannot allocate in the stack
    QObject *childObject = new QObject(&parentObject);

    // No need to delete the child object, as parent will do it
    // Still possible to delete it
    delete childObject;
    if (childObject)
        qWarning() << "Dangling pointer";

    // Guarded pointer to the child object
    // The referenced object may be accessed with the member data()
    QPointer<QObject> childObject2(new QObject(&parentObject));
    simpleFunction(childObject2, string);

    delete childObject2;
    if (!childObject2)
        qWarning() << "Dangling pointer solved";

    return EXIT_SUCCESS;
}
