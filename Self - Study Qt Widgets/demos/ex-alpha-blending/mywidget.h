/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class BlobWidget;

/*
 * This is the window widget containing the pushbuttons.
 * The blob widget is a child of it, too.
 */

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = Q_NULLPTR);
    
signals:
    
protected slots:
    void selectButton();

private:
    BlobWidget* m_blobWidget;
};

#endif // MYWIDGET_H
