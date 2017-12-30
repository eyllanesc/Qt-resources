/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include "raycastingwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RayCastingWidget w;
    w.setWindowTitle("Raycasting");

    w.resize(640, 480);
    w.show();

    return app.exec();
}
