/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);       // Loads the QPA plugin
    QPushButton button("Hello world");  // Creates a widget
    button.show();
    return app.exec();                  // Starts the event loop
}
