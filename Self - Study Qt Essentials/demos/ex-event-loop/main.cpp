/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include "custombutton.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton *modalWidgetButton = new QPushButton("Show Modal Widget");
    QPushButton *nonModalWidgetButton = new QPushButton("Show non-Modal Widget");

    CustomButton modalButton;
    CustomButton nonModalButton;
    QObject::connect(modalWidgetButton, &QPushButton::clicked, &modalButton, &CustomButton::showModal);
    QObject::connect(nonModalWidgetButton, &QPushButton::clicked, &nonModalButton, &CustomButton::showNonModal);

    QWidget top;
    QVBoxLayout *layout = new QVBoxLayout(&top);
    layout->addWidget(modalWidgetButton);
    layout->addWidget(nonModalWidgetButton);
    top.show();

    return app.exec();
}


