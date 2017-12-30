/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QEvent>
#include <QMouseEvent>
#include "quotebutton.h"

QuoteButton::QuoteButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent), m_quoteNo(-1)
{
    // Quotes from Office Space!
    m_quotes.append("I'm a Michael Bolton fan. Could you play it for me?");
    m_quotes.append("About your TPS reports...");
    m_quotes.append("You will have to come in Saturday, will'ya?");
    m_quotes.append("we're putting new coversheets on all the TPS reports *before* they go out now");
    m_quotes.append("bear with me for just a second");
    m_quotes.append("You see Bob, it's not that I'm lazy, it's that I just don't care.");
    m_quotes.append("No, not again.");
    m_quotes.append("I swear to God, one of these days...");
    m_quotes.append("that's just a straight shooter with upper management written all over him");
    m_quotes.append("Standard operating procedure.");
    m_quotes.append("I could set the building on fire." );
    m_quotes.append("Excuse me, I believe you have my stapler... ");
    m_quotes.append("I could put... I could put... strychnine in the guacamole.");
    m_quotes.append("What am I gonna do with 40 subscriptions to Vibe?");
    m_quotes.append("Oh, and next Friday... is Hawaiian shirt day...");
    m_quotes.append("You know, minimum security prison is no picnic.");
    m_quotes.append("I have people skills.");
    m_quotes.append("I can't believe what a bunch of nerds we are.");
    m_quotes.append("The ratio of people to cake is too big.");

    connect(this, &QuoteButton::clicked, this, &QuoteButton::sendQuote);
}

void QuoteButton::sendQuote()
{
    m_quoteNo = (m_quoteNo + 1) % m_quotes.size();
    Q_EMIT quote(m_quotes[m_quoteNo]);
}

bool QuoteButton::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QWidget *widget = qobject_cast<QWidget *>(watched->parent());

        if (widget) {
            QPoint position(widget->pos());
            if (mouseEvent->button() == Qt::LeftButton)
                widget->move(position.x() - 10, position.y());
            else if (mouseEvent->button() == Qt::RightButton)
                widget->move(position.x() + 10, position.y());
        }
    }

    return QPushButton::eventFilter(watched, event);
}
