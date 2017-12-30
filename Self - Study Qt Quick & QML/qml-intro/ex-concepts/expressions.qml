/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Item {
    width: 400; height: 200

    Rectangle {
        x: 100; y: 50
        width: height * 2; height: parent.height / 2
        color: "lightblue"
    }
}
