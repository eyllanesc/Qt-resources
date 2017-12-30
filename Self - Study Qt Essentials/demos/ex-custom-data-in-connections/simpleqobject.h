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
#include "data.h"

class SimpleQObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Data data MEMBER m_data)
public:
    explicit SimpleQObject(QObject *parent = 0);

private:
    int m_integer;
    Data m_data;

};

#endif // SIMPLEQOBJECT_H
