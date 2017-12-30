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
    width: 400; height: 400;
    color: "lightblue"

    Rectangle {
        id: rectangle1
        x: 150; y: 150
        width: 100
        height: 100
        color: "green"
    }

    ColorAnimation {
        target: rectangle1
        property: "color"
        from: Qt.rgba(0,0.5,0,1)
        to: Qt.rgba(1,1,1,1)
        duration: 1000
        running: true
    }
}
