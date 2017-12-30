/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "selectcolor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SelectColor widget;
    widget.show();

    return app.exec();
}
