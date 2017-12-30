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
#include "masterbutton.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QPushButton *slave = new QPushButton("Slave");
    MasterButton *master = new MasterButton("Master", slave);

    QWidget top;
    QVBoxLayout *layout = new QVBoxLayout(&top);
    layout->addWidget(master);
    layout->addWidget(slave);
    top.show();

    return app.exec();
}


