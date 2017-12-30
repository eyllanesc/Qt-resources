/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "customevent.h"
#include "custombutton.h"
#include "customapplication.h"

int main(int argc, char *argv[])
{
    CustomApplication application(argc, argv);

    CustomButton button;
    // Application-global event filter
    application.installEventFilter(&button);
    button.show();

    return application.exec();
}
