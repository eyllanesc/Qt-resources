/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <QObject>

class SimpleClass : public QObject
{
    Q_OBJECT
public:
    explicit SimpleClass(QObject *parent = 0);
    ~SimpleClass();
};

#endif // SIMPLECLASS_H
