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
    width: 150; height: 150; color: "black"

    Image {
        id: rocket
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "../images/rocket.svg"
    }

    states: [
        State { name: "up"
                PropertyChanges { target: rocket; rotation: 0 } },
        State { name: "down"
                PropertyChanges { target: rocket; rotation: 180 } }
    ]

    state: "up"

    transitions: [
        Transition {
            from: "*"; to: "*"
            PropertyAnimation {
                target: rocket
                properties: "rotation"; duration: 1000
            }
        }
    ]
    MouseArea { anchors.fill: parent
                onClicked: parent.state == "up" ?
                    parent.state = "down" : parent.state = "up" }
}
