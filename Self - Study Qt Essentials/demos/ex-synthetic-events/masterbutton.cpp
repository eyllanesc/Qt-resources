/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QEvent>
#include <QApplication>
#include <QMouseEvent>

#include "masterbutton.h"

MasterButton::MasterButton(QString txt, QPushButton *slaveButton, QPushButton *parent) :
    QPushButton(txt, parent),
    m_slave(slaveButton)
{
}

bool MasterButton::event(QEvent *event)
{
    if (QEvent::MouseButtonPress <= event->type() && event->type() <= QEvent::KeyRelease)
    {
        // Sending an event - the event is not destroyed by Qt
        qApp->sendEvent(m_slave, event);

        // Posting an event - the event is destroyed by Qt
        qApp->postEvent(m_slave, new QMouseEvent(*static_cast<QMouseEvent*>(event)));
    }
    return QPushButton::event(event);
}
