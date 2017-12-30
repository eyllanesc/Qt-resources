/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QCoreApplication>
#include <QtDebug>
#include "custombutton.h"
#include "customevent.h"

CustomButton::CustomButton(QWidget *parent) :
    QPushButton("Click on me to send a custom event", parent)
{
    // Object-specific event filter
    installEventFilter(this);

    connect(this, &CustomButton::clicked, this, &CustomButton::sendCustomEvent);
}

void CustomButton::sendCustomEvent()
{
    // Synchronous, event object may be allocated in the stack
    CustomEvent event;
    event.setData("Custom event");
    qApp->sendEvent(this, &event);
}

bool CustomButton::event(QEvent *event)
{
    if (event->type() == customEventType)
        qDebug() << "Custom event handled in event() function" << "Event data" << static_cast<CustomEvent *>(event)->data();
    return QPushButton::event(event);
}

bool CustomButton::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == customEventType)
        qDebug() << "Custom event handled in eventFilter() function";
    return QPushButton::eventFilter(watched, event);
}

void CustomButton::customEvent(QEvent *event)
{
    if (event->type() == customEventType)
        qDebug() << "Custom event handled in customEvent() function";
    return QPushButton::customEvent(event);
}
