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
        color: "green"
        width: height
        NumberAnimation on height {
            from: 0; to: 400
            duration: 1000
            running: true
        }
    }
}
