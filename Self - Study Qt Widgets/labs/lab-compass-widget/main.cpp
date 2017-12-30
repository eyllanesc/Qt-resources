/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "compasspanel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CompassPanel panel;
    panel.show();
    return app.exec();
}
