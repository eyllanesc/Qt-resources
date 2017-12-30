/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QString>
#include "data.h"

Data::Data() :
    m_integer(-1), m_pointer(0), m_string()
{
}

Data::Data(int integerArg, int *pointerArg, const QString &stringArg) :
    m_integer(integerArg), m_pointer(pointerArg), m_string(stringArg)
{
}

bool Data::operator !=(const Data &data) const
{
    if (data.m_integer != m_integer || data.m_pointer != m_pointer || data.m_string != m_string)
        return true;
    else
        return false;
}
