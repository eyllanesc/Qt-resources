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
    property real margin: 35
    width: 400; height: 400

    Rectangle {
        id: lightblue_square
        color: focus ? "red" : "lightblue"
        anchors { top: parent.top; topMargin: margin; left: parent.left; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }

        KeyNavigation.right: green_square
    }

    Rectangle {
        id: green_square
        color: focus ? "red" : "green"
        anchors { top: parent.top; topMargin: margin; left: lightblue_square.right; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375

        MouseArea {
            anchors.fill: parent
        }
    }

    Rectangle {
        id: silver_square
        color: focus ? "red" : "silver"
        anchors { top: lightblue_square.bottom; topMargin: margin; left: parent.left; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375
    }

    Rectangle {
        id: purple_square
        color: focus ? "red" : "purple"
        anchors { top: green_square.bottom; topMargin: margin; left: silver_square.right; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375
    }
}
