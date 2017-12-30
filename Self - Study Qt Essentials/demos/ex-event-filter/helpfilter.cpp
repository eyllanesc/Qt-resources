/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QStatusBar>
#include <QEvent>
#include "helpfilter.h"

HelpFilter::HelpFilter(QStatusBar *bar, const QString &txt, QObject *parent) :
    QObject(parent), statusBar(bar), text(txt)
{
}

bool HelpFilter::eventFilter(QObject *receiver, QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        statusBar->showMessage(text, 5000);
    }
    else if (event->type() == QEvent::Leave) {
        statusBar->clearMessage();
    }

    return QObject::eventFilter(receiver, event);
}
