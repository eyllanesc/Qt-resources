/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Rectangle {
    width: 400; height: 400
    color: "lightblue"

    Rectangle {
        x: 50; y: 50; width: parent.width - 2 * x; height: parent.height - 2 * y
        color: "green"

        Rectangle {
            x: parent.width - 2 * width; y: parent.height - 3 * height; width: 50; height: 50
            color: "white"
        }
    }
}
