/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SENDER_H
#define SENDER_H

#include <QPushButton>

QT_FORWARD_DECLARE_CLASS(Data)
QT_FORWARD_DECLARE_CLASS(SimpleQObject)

class Sender : public QPushButton
{
    Q_OBJECT
public:
    explicit Sender(QWidget *parent = 0);
    ~Sender();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void data(const Data &);
    void data2(SimpleQObject *);
    void closed();

protected Q_SLOTS:
    void sendData();

private:
    int m_integer;
    SimpleQObject *m_simple;
};

#endif // SENDER_H
