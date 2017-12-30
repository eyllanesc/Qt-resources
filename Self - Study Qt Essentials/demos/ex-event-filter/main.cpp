/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QMainWindow>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>

#include "helpfilter.h"

int main( int argc, char**argv)
{
    QApplication app(argc, argv);

    QMainWindow win;

    QCheckBox* box = new QCheckBox("CheckBox");
    HelpFilter *boxFilter = new HelpFilter(win.statusBar(), "Text for checkbox");
    box->installEventFilter(boxFilter);

    QLineEdit* edit= new QLineEdit;
    HelpFilter *editFilter = new HelpFilter(win.statusBar(), "Text for lineEdit");
    edit->installEventFilter(editFilter);

    QWidget* top = new QWidget;
    win.setCentralWidget(top);

    QVBoxLayout* layout = new QVBoxLayout(top);
    layout->addWidget(box);
    layout->addWidget(edit);

    win.show();

    return app.exec();
}
