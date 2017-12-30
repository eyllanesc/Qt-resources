/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "stopwatch.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StopWatch watch;
    watch.resize(80, 40);
    watch.show();

    return app.exec();
}
