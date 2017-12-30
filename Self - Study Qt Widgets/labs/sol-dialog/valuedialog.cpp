/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "valuedialog.h"

ValueDialog::ValueDialog(QWidget *parent)
    : QDialog(parent)
{
    spin = new QSpinBox;
    slider = new QSlider(Qt::Horizontal);
    connect(spin, QOverload<int>::of(&QSpinBox::valueChanged), this, &ValueDialog::setValue);
    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);
    connect(slider, &QSlider::valueChanged, this, &ValueDialog::valueChanged);

    box = new QDialogButtonBox;
    box->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    connect(box, &QDialogButtonBox::accepted, this, &ValueDialog::accept);
    connect(box, &QDialogButtonBox::rejected, this, &ValueDialog::reject);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(spin);
    layout->addWidget(slider);
    layout->addWidget(box);
    setLayout(layout);
}

void ValueDialog::setValue(int value)
{
    spin->setValue(value);
}

void ValueDialog::accept()
{
    if(slider->value() < 50)
        QDialog::accept();
    else
        QMessageBox::information(this, "Value Check", "Value must be below 50");
}
