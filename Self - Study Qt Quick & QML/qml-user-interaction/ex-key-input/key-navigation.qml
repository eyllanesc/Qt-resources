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
    property real marging: 25

    width: 400; height: 200; color: "black"

    Rectangle { id: leftRect
                width: parent.width * 0.375; height: parent.height * 0.75
                anchors { top: parent.top; topMargin: marging; left: parent.left; leftMargin: marging }
                color: focus ? "red" : "darkred"
                KeyNavigation.right: rightRect
                focus: true }

    Rectangle { id: rightRect
                width: parent.width * 0.375; height: parent.height * 0.75
                anchors { top: parent.top; topMargin: marging; left: leftRect.right; leftMargin: marging }
                color: focus ? "#00ff00" : "green"
                KeyNavigation.left: leftRect }
}
