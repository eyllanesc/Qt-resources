/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SIMPLEDATA_H
#define SIMPLEDATA_H

#include <QSharedData>

class SimpleData : public QSharedData
{
public:
    SimpleData();
    ~SimpleData();

    int value() const;
    void setValue(int newValue);

private:
    int m_member;
};

#endif // SIMPLEDATA_H
