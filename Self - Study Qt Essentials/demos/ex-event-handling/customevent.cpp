/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "customevent.h"

CustomEvent::CustomEvent() :
    QEvent(customEventType),
    m_eventData("")
{
}

QString CustomEvent::data() const
{
    return m_eventData;
}

void CustomEvent::setData(const QString &data)
{
    if (data != m_eventData)
        m_eventData = data;
}
