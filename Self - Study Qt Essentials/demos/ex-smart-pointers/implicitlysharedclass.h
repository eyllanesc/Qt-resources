/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef IMPLICITLYSHAREDCLASS_H
#define IMPLICITLYSHAREDCLASS_H

#include <QSharedDataPointer>
#include "simpledata.h"

class ImplicitlySharedClass
{
public:
    ImplicitlySharedClass();
    ImplicitlySharedClass(ImplicitlySharedClass &another);

    int nofDataReferences() const;

    int value() const;
    void setValue(int newValue);

private:
    QSharedDataPointer<SimpleData> d;
};

#endif // IMPLICITLYSHAREDCLASS_H
