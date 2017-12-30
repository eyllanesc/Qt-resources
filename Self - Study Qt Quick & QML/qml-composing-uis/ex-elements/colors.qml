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
    width: 300; height: 100

Rectangle {
        id: rectangle1
        x: 0; y: 0; width: parent.width / 3; height: parent.height; color: "#ff0000"
    }
    Rectangle {
        id: rectangle2
        x: rectangle1.width; width: parent.width / 3; height: parent.height
        color: Qt.rgba(0,0.75,0,1)
    }
    Rectangle {
        x: rectangle1.width + rectangle2.width; width: parent.width / 3; height: parent.height; color: "blue"
    }
}
