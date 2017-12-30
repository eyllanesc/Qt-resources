/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "explicitlysharedclass.h"

ExplicitlySharedClass::ExplicitlySharedClass() :
    d(new SimpleData)
{
}

ExplicitlySharedClass::ExplicitlySharedClass(ExplicitlySharedClass &another)
{
    d = another.d;
}

int ExplicitlySharedClass::nofDataReferences() const
{
    return d.data()->ref;
}

int ExplicitlySharedClass::value() const
{
    return d.data()->value();
}

void ExplicitlySharedClass::setValue(int newValue)
{
    d.data()->setValue(newValue);
}

void ExplicitlySharedClass::detach()
{
    d.detach();
}
