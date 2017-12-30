/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BLOBWIDGET_H
#define BLOBWIDGET_H

#include <QWidget>

/*
 * This is the child widget which paints a semi-transparent blob
 * It doesn't draw all pixels inside its rect(), and doesn't use setAutoFillBackground(true)
 */

class BlobWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BlobWidget(QWidget *parent = Q_NULLPTR);
    
protected:
     void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;

    
};

#endif // BLOBWIDGET_H
