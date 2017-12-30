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

class CustomButton : public QPushButton
{
public:
    CustomButton(QWidget *parent = Q_NULLPTR);

public:
    Q_SLOT void sendCustomEvent();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
    void customEvent(QEvent *event) Q_DECL_OVERRIDE;
};

#endif // CUSTOMBUTTON_H
