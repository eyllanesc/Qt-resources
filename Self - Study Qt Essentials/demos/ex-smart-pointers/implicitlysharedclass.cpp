/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "implicitlysharedclass.h"

ImplicitlySharedClass::ImplicitlySharedClass() :
    d(new SimpleData)
{   
}

ImplicitlySharedClass::ImplicitlySharedClass(ImplicitlySharedClass &another)
{
    d = another.d;
}

int ImplicitlySharedClass::nofDataReferences() const
{
    return d.data()->ref;
}

int ImplicitlySharedClass::value() const
{
    return d.data()->value();
}

void ImplicitlySharedClass::setValue(int newValue)
{
    d.data()->setValue(newValue);
}

