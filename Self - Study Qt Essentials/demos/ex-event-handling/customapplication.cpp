/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include "customapplication.h"
#include "customevent.h"

CustomApplication::CustomApplication(int argc, char *argv[]) :
    QApplication(argc, argv)
{
}

bool CustomApplication::notify(QObject *receiver, QEvent *event)
{
    Q_UNUSED(receiver)
    if (event->type() == customEventType)
        qDebug() << "Custom event handled in notify() function";
    return QApplication::notify(receiver, event);
}

