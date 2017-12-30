/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "slider.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Slider *slider = new Slider(Qt::Horizontal);
    slider->setRange(-100, 100);

    QLCDNumber *lcd = new QLCDNumber;
    // Ensure that the widget can grow when resizing the window, ignore this for now
    lcd->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    QObject::connect(slider, &Slider::valueChanged, lcd, qOverload<int>(&QLCDNumber::display));

    slider->setValue(40);

    QWidget top;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(lcd);
    top.setLayout(layout);

    top.show();
    return app.exec();
}
