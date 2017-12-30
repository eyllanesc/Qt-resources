/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "timer.h"

#include <QTimer>

Timer::Timer(QObject *parent)
    : QObject(parent),
      m_timer(new QTimer(this))
{
    m_timer->setInterval(1000);
    m_timer->start();
}
