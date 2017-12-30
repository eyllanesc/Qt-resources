/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include "simpleqobject.h"

QT_FORWARD_DECLARE_CLASS(Data)

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);
    
public Q_SLOTS:
    void data(const Data& data);
    void data2(SimpleQObject *);
    void quit();
};

#endif // RECEIVER_H
