/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef INTERVALSETTINGS_H
#define INTERVALSETTINGS_H

#include <QObject>

class IntervalSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int duration READ duration WRITE setDuration NOTIFY durationChanged )
    Q_ENUMS( Unit )
    Q_PROPERTY( Unit unit READ unit WRITE setUnit NOTIFY unitChanged )

public:
    enum Unit { Minutes, Seconds, MilliSeconds };
    explicit IntervalSettings(QObject *parent = 0);

    int duration() const;
    void setDuration(int);

    Unit unit() const;
    void setUnit( Unit );

    int timeoutInMilliSeconds() const;

signals:
    void durationChanged();
    void unitChanged();

private:
    int m_duration;
    Unit m_unit;
};

#endif // INETRVALSETTINGS_H
