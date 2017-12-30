/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SIMPLEQOBJECT_H
#define SIMPLEQOBJECT_H

#include <QObject>
#include "contact.h"

class SimpleQObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Contact contact MEMBER m_contact NOTIFY contactChanged)
public:
    explicit SimpleQObject(QObject *parent = 0);

    Q_SIGNAL void contactChanged(const Contact &);
    Q_SLOT void changeContact(const Contact &);

private:
    Contact m_contact;
};

#endif // SIMPLEQOBJECT_H
