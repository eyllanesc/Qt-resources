/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include <QObject>

class IntervalSettings;

class QTimer;

class Timer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool active READ isActive NOTIFY activeChanged)
    Q_PROPERTY(IntervalSettings* interval READ interval WRITE setInterval NOTIFY intervalChanged)

public:
    explicit Timer( QObject* parent = 0 );

    bool isActive();

    Q_INVOKABLE int randomInterval(int min, int max) const;

    IntervalSettings *interval() const;
    void setInterval(IntervalSettings *);

public slots:
    void start();
    void stop();

signals:
    void timeout();

    void intervalChanged();
    void activeChanged();

private:
    QTimer *m_timer;
    IntervalSettings *m_settings;
};

#endif // TIMER_H
