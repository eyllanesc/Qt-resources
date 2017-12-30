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
    id: container

    property variant flickableArea

    Rectangle {
        radius: 5
        color: "black"
        opacity: 0.3
        border.color: "white"
        border.width: 2
        x: 0
        y: flickableArea.visibleArea.yPosition * container.height
        width: parent.width
        height: flickableArea.visibleArea.heightRatio * container.height
    }
    states: [
        State {
            name: "show"
            when: flickableArea.movingVertically
            PropertyChanges {
                target: container
                opacity: 1
            }
        }
    ]
    transitions: [
        Transition {
            from: "*"
            to: "*"
            NumberAnimation {
                target: container
                properties: "opacity"
                duration: 400
            }
        }
    ]
}
