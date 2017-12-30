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
        focus: true

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }

        KeyNavigation.right: green_square
        KeyNavigation.down: silver_square
    }

    Rectangle {
        id: green_square
        color: focus ? "red" : "green"
        anchors { top: parent.top; topMargin: margin; left: lightblue_square.right; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }

        KeyNavigation.left: lightblue_square
        KeyNavigation.down: purple_square
    }

    Rectangle {
        id: silver_square
        color: focus ? "red" : "silver"
        anchors { top: lightblue_square.bottom; topMargin: margin; left: parent.left; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }

        KeyNavigation.right: purple_square
        KeyNavigation.up: lightblue_square
    }

    Rectangle {
        id: purple_square
        color: focus ? "red" : "purple"
        anchors { top: green_square.bottom; topMargin: margin; left: silver_square.right; leftMargin: margin }
        width: parent.width * 0.375 ; height: parent.height * 0.375

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }

        KeyNavigation.left: silver_square
        KeyNavigation.up: green_square
    }
}
