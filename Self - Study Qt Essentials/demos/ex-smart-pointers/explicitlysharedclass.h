/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EXPLICITLYSHAREDCLASS_H
#define EXPLICITLYSHAREDCLASS_H

#include <QExplicitlySharedDataPointer>
#include "simpledata.h"

class ExplicitlySharedClass
{
public:
    ExplicitlySharedClass();
    ExplicitlySharedClass(ExplicitlySharedClass &another);

    int nofDataReferences() const;

    int value() const;
    void setValue(int newValue);

    void detach();

private:
    QExplicitlySharedDataPointer<SimpleData> d;
};

#endif // EXPLICITLYSHAREDCLASS_H
