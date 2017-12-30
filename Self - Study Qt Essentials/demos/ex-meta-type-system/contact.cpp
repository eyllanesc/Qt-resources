/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "contact.h"

Contact::Contact()
    : m_name("")
{  
}

void Contact::setName(const QString name)
{
    if (m_name != name)
        m_name = name;
}

QString Contact::name() const
{
    return m_name;
}

bool Contact::operator !=(const Contact &contact) const
{
    return contact.name() != m_name;
}




