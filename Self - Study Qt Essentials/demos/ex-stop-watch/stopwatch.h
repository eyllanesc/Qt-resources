/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLabel>

class StopWatch : public QLabel
{
    Q_OBJECT

public:
    StopWatch(QWidget *parent = 0);

protected Q_SLOTS: // or slots
    void shot();

private:
    int m_secs;
};

#endif
