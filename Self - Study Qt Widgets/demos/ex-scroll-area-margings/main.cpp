/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include "scrollarea.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  ScrollArea sa;  
  sa.show();

  return app.exec();
}

