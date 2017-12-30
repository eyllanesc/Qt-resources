/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtWidgets>
#include "mainwindow.h"

int main (int argc, char *argv[]) {
	QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    if (app.arguments().contains("-testobjects")) {
        mw.createTestObjects();
     }
	return app.exec();

}
