/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "timer.h"

#include <QDebug>
#include <QTimer>

Timer::Timer(QObject *parent)
    : QObject(parent),
      m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &Timer::timeout);
}

void Timer::setInterval(int msec)
{
    if (m_timer->interval() == msec)
        return;
    m_timer->stop();
    m_timer->setInterval(msec);
    m_timer->start();
    Q_EMIT intervalChanged();
    qDebug() << Q_FUNC_INFO << "interval =" << m_timer->interval();
}

int Timer::interval()
{
    return m_timer->interval();
}
