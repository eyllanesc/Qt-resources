/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>

#include "clock.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Clock clock;
    clock.show();

    return app.exec();
}
