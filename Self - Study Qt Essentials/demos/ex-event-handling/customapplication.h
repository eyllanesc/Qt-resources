/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CUSTOMAPPLICATION_H
#define CUSTOMAPPLICATION_H

#include <QApplication>

class CustomApplication : public QApplication
{
public:
    CustomApplication(int argc, char *argv[]);

protected:
    bool notify(QObject *receiver, QEvent *event) Q_DECL_OVERRIDE;
};

#endif // CUSTOMAPPLICATION_H
