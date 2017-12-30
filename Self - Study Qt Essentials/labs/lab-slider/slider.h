/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SLIDER_H
#define SLIDER_H

#include <QtWidgets>

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)

class Slider : public QWidget
{
public:
    Slider(Qt::Orientation orient = Qt::Horizontal, QWidget *parent = 0);
};

#endif // SLIDER_H
