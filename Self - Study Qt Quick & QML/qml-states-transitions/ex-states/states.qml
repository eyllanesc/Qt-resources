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
    property real xMargin: 25
    property real yMargin: 15
    width: 150; height: 250

    Rectangle {
        id: stopLight
        anchors { top: parent.top; topMargin: yMargin; left: parent.left; leftMargin: xMargin }
        width: parent.width * 0.75; height: parent.height * 0.4
    }
    Rectangle {
        id: goLight
        anchors { top: stopLight.bottom; topMargin: yMargin; left: parent.left; leftMargin: xMargin }
        width: parent.width * 0.75; height: parent.height * 0.4
    }

    states: [
        State {
            name: "stop"
            PropertyChanges { target: stopLight; color: "red" }
            PropertyChanges { target: goLight; color: "black" }
        },
        State {
            name: "go"
            PropertyChanges { target: stopLight; color: "black" }
            PropertyChanges { target: goLight; color: "green" }
        }
    ]

    state: "stop"

    MouseArea {
        anchors.fill: parent
        onClicked: parent.state == "stop" ?
                       parent.state = "go" : parent.state = "stop"
    }
}
