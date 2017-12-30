/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QVariant>
#include <QBuffer>
#include <QDataStream>
#include <QDebug>
#include "contact.h"
#include "simpleqobject.h"

QDataStream &operator<<(QDataStream &out, const Contact &contact)
{
    out << contact.name();
    return out;
}

QDataStream &operator>>(QDataStream &in, Contact &contact)
{
    QString name;
    in >> name;
    contact.setName(name);
    return in;
}

int main(int, char *[])
{
    Contact contact;
    contact.setName("Peter");

    QVariant variant = QVariant::fromValue(contact);
    Contact contact2 = variant.value<Contact>();

    qDebug() << contact2.name();    // "Peter"
    qDebug() << variant.typeName(); // prints "Contact"
    int type(variant.userType());   // 1025 (QMetaType::User + 1)
    qDebug() << qRegisterMetaType<Contact>() << qMetaTypeId<Contact>();

    Contact *contact3(static_cast<Contact *>(QMetaType::create(type)));
    contact3->setName("Ann");

    // Serialization
    qRegisterMetaTypeStreamOperators<Contact>();

    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QDataStream out(&buffer);
     if (QMetaType::save(out, type, contact3)) // Called by QVariant << operator
        qDebug() << buffer.data();

    QDataStream in(buffer.data());
    Contact contact4;
    if (QMetaType::load(in, type, static_cast<void *>(&contact4)))
        qDebug() << contact4.name();

    // Destroy using QMetaObject
    QMetaType contact5(type);
    if (contact5.metaObject())
        qDebug() << "Type has a meta-object";
    contact5.destruct(contact3);

    // Custom type as a signal parameter
    // We have a single threaded program, registration is not needed
    SimpleQObject object;
    object.connect(&object, &SimpleQObject::contactChanged, &object, &SimpleQObject::changeContact);
    object.setProperty("contact", QVariant::fromValue(contact));

    qDebug() << object.property("contact").value<Contact>().name();
}
