/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "slider.h"

Slider::Slider(Qt::Orientation orient, QWidget *parent)
    : QWidget(parent)
{
    m_slider = new QSlider(orient);
    m_display = new QLabel;
    m_display->setAlignment(Qt::AlignRight);

    // setNum is overloaded to both setNum(int) and setNum(double), hence the ugly syntax.
    connect(m_slider, &QSlider::valueChanged, m_display, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    // Signal to Signal connection
    connect(m_slider, &QSlider::valueChanged, this, &Slider::valueChanged);

    QBoxLayout *layout = 0;
    if (orient == Qt::Horizontal) {
        layout = new QHBoxLayout;
    }
    else {
        layout = new QVBoxLayout;
    }

    // If we don't set the margin to 0 then we will get a double margin when using this m_slider, which looks odd.
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_slider);
    layout->addWidget(m_display);
    setLayout(layout);
}

void Slider::setValue(int value)
{
    m_slider->setValue(value);
}

void Slider::setRange(int min, int max)
{
    m_slider->setRange(min, max);
    m_display->setFixedWidth(maxWidth(minimum(), maximum()));
}

void Slider::setMinimum(int min)
{
    setRange(min, maximum());
}

void Slider::setMaximum(int max)
{
    setRange(minimum(), max);
}

int Slider::value() const
{
    return m_slider->value();
}

int Slider::minimum() const
{
    return m_slider->minimum();
}

int Slider::maximum() const
{
    return m_slider->maximum();
}

int Slider::maxWidth(int min, int max) const
{
    int maxValue = qMax(qAbs(min), qAbs(max));

    // Count the amount of digits.
    int digits = 0;
    while (maxValue >= 1) {
        ++digits;
        maxValue /= 10;
    }

    // Find the maximum width of any digit.
    int maxWidth = 0;
    for (int i = 0; i < 10; ++i) {
        maxWidth = qMax(maxWidth, fontMetrics().width(QString::number(i)));
    }

    // if min or max is negative, reserve space for a minus-sign
    if (min < 0 || max < 0)
        return maxWidth * digits + fontMetrics().width('-');
    else
        return maxWidth * digits;
}
