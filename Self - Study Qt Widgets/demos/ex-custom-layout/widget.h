/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class CustomLayout;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = Q_NULLPTR);
    ~Widget();

private:
    QPushButton *shortButton;
    QPushButton *longerButton;
    QPushButton *differentTextButton;
    QPushButton *moreTextButton;
    QPushButton *evenLongerButtonTextButton;

    CustomLayout *layout;
};

#endif // WIDGET_H
