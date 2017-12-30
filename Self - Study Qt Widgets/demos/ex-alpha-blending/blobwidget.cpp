/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QPainter>
#include "blobwidget.h"

BlobWidget::BlobWidget(QWidget *parent) :
    QWidget(parent)
{
    // Without this attribute clicks in the widget's rectangle
    // wouldn't be received by the push buttons.
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

void BlobWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::black, 3 ));

    const QRect r = rect();
    p.fillRect(r, QColor(10, 50, 180, 60 /*transparency*/));
}
