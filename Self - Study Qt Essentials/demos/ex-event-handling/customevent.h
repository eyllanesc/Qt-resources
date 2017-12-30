/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H

#include <QEvent>
#include <QString>

const QEvent::Type customEventType = QEvent::Type(QEvent::User + 1);

class CustomEvent : public QEvent
{
public:
    CustomEvent();
    QString data() const;
    void setData(const QString &data);

private:
    QString m_eventData;
};

#endif // CUSTOMEVENT_H
