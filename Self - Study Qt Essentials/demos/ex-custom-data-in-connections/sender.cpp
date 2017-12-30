/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "sender.h"
#include "data.h"
#include "simpleqobject.h"
#include <QDebug>

Sender::Sender(QWidget *parent) :
    QPushButton("Click on me", parent),
    m_simple(new SimpleQObject)
{
    connect(this, &Sender::clicked, this, &Sender::sendData);
    m_integer = 42;
    setMinimumSize(200, 30);
}

Sender::~Sender()
{
    delete m_simple;
}

void Sender::closeEvent(QCloseEvent *event)
{
    Q_EMIT closed();
    QPushButton::closeEvent(event);
}

void Sender::sendData()
{
    Data d(10, &m_integer, "hello");
    Q_EMIT data(d);
    Q_EMIT data2(m_simple);
}

