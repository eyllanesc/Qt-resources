/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef QUOTEBUTTON_H
#define QUOTEBUTTON_H

#include <QPushButton>
#include <QStringList>

class QuoteButton: public QPushButton
{
    Q_OBJECT

public:
    QuoteButton(const QString &text, QWidget *parent = 0);

Q_SIGNALS:
    void quote(const QString &);

protected Q_SLOTS:
    void sendQuote();

private:
    int m_quoteNo;
    QStringList m_quotes;
};

#endif // QUOTEBUTTON_H
