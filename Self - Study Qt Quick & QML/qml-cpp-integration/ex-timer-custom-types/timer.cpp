/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "timer.h"

#include <QDebug>
#include <QTimer>
#include "IntervalSettings.h"

Timer::Timer( QObject* parent )
    : QObject( parent ),
      m_timer( new QTimer( this ) ),
      m_settings( new IntervalSettings )
{
    connect( m_timer, &QTimer::timeout, this, &Timer::timeout);
}

bool Timer::isActive()
{
    return m_timer->isActive();
}

int Timer::randomInterval( int min, int max ) const
{
    int range = max - min;
    int msec = min + qrand() % range;
    return msec;
}

void Timer::start()
{
    m_timer->setInterval(m_settings->timeoutInMilliSeconds());
    if ( m_timer->isActive() )
        return;
    m_timer->start();
    emit activeChanged();
}

void Timer::stop()
{
    if ( !m_timer->isActive() )
        return;
    m_timer->stop();
    emit activeChanged();
}

IntervalSettings * Timer::interval() const
{
    return m_settings;
}

void Timer::setInterval(IntervalSettings *settings)
{
    if ( m_settings != settings ) {
        delete m_settings;
        m_settings = settings;
        emit intervalChanged();
    }
}
