/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "simpleqobject.h"
#include <QDebug>

SimpleQObject::SimpleQObject(QObject *parent) : QObject(parent)
{
}

void SimpleQObject::changeContact(const Contact &contact)
{
    if (contact != m_contact) {
        m_contact = contact;
        Q_EMIT contactChanged(contact);
    }
}
