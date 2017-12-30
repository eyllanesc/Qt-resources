/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

QT_FORWARD_DECLARE_CLASS(QEventLoop)

class CustomButton : public QPushButton
{
public:
    CustomButton(QWidget *parent = Q_NULLPTR);
    ~CustomButton();

public:
    Q_SLOT void showModal();
    Q_SLOT void showNonModal();

private:
    bool m_modal;
    QEventLoop *m_eventLoop;
};

#endif // CUSTOMBUTTON_H
