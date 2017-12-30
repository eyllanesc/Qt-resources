/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include <QThread>

#include "receiver.h"
#include "data.h"


Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

void Receiver::data(const Data &data)
{
    qDebug() << "Receiver says: " << data.m_integer << *data.m_pointer << data.m_string;
}

void Receiver::data2(SimpleQObject *qtObject)
{
    qDebug() << qtObject->property("data").value<Data>().m_string;

}

void Receiver::quit()
{
    // Return from the thread event loop
    // Thread will finish
    thread()->quit();
}

