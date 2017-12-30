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
    id: root
    property real margin: 5
    width: 100; height: 150

    Rectangle {
        id: groove
        x: 10; y: 25
        width: parent.width * 0.5 ; height: parent.height * 0.67
        color: "gray"
        border.color: "lightgray"
        border.width: 4
    }

    Rectangle {
        id: handle
        anchors { left: groove.left; leftMargin: margin; right: groove.right; rightMargin: margin }
        height: parent.height * 0.2
        y: groove.y + margin
        color: "lightgray"
    }
}


