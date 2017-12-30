/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QObject>
#include <QPointer>
#include <QDebug>
#include "simpleclass.h"
#include "implicitlysharedclass.h"
#include "explicitlysharedclass.h"

int main(int, char *[])
{
    // QPointer
    QObject parent;          // Stack allocation
    QObject *child = new QObject(&parent); // Heap allocation for the child

    // Someone wants to store the child pointer
    QPointer<QObject> childPointer(child);
    delete child;
    if (childPointer) // if (child) would result the next line to be called
        qDebug() << "Dangling pointer";

    // QScopedPointer
    SimpleClass *simpleObject = new SimpleClass;
    {
        // One way to get notified that an object has been destroyed is to use QObject::destroyed() signal
        simpleObject->connect(simpleObject, &SimpleClass::destroyed, [&] (void) { simpleObject = Q_NULLPTR; });
        QScopedPointer<SimpleClass> simpleObjectPointer(simpleObject);
    }

    if (simpleObject)
        qDebug() << "simpleObject is a dangling pointer";

    // QSharedPointer
    SimpleClass *anotherSimpleObject = new SimpleClass;
    QSharedPointer<SimpleClass> sharedPointer(anotherSimpleObject);
    {
        QSharedPointer<SimpleClass> anotherSharedPointer(sharedPointer);
        // anotherSimpleObject exists at least as long as we keep anotherSharedPointer
        // in memory. No need to worry, if anybody else uses the object in this or another thread
    }
    // anotherSimpleObject is not deleted yet, as there is still one reference to the object

    // Weak reference can be used to check, whether the referenced object still exists
    // It cannot be used to dereference the pointer
    QWeakPointer<SimpleClass> weakPointer(sharedPointer);
    if (weakPointer)
        qDebug() << "Shared pointer still exists";
    sharedPointer.clear();
    if (!weakPointer)
        qDebug() << "Shared pointer does not exist anymore";

    // QSharedDataPointer
    ImplicitlySharedClass basicObject1;
    ImplicitlySharedClass basicObject2(basicObject1);
    qDebug() << "Data references" << basicObject1.nofDataReferences();
    qDebug() << "basicObject1 data value" << basicObject1.value();
    qDebug() << "basicObject2 data value" << basicObject2.value();

    basicObject2.setValue(43);
    qDebug() << "Data references" << basicObject1.nofDataReferences();
    qDebug() << "basicObject1 data value" << basicObject1.value();
    qDebug() << "basicObject2 data value" << basicObject2.value();

    // QExplicitlySharedDataPointer
    ExplicitlySharedClass basicObject3;
    ExplicitlySharedClass basicObject4(basicObject3);
    basicObject3.setValue(44);
    qDebug() << "Data references" << basicObject3.nofDataReferences();
    qDebug() << "basicObject3 data value" << basicObject3.value();
    qDebug() << "basicObject4 data value" << basicObject4.value();

    basicObject3.detach();
    basicObject3.setValue(45);
    qDebug() << "Data references" << basicObject3.nofDataReferences();
    qDebug() << "basicObject3 data value" << basicObject3.value();
    qDebug() << "basicObject4 data value" << basicObject4.value();

    return EXIT_SUCCESS;
}
