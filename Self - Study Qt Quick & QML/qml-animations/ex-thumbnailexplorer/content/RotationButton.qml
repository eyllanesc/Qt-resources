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
    width: 50
    height: 50

    property int angle: 0
    property int duration: 250

    Button {
        id: button

        // From button center
        property int startX: container.width - width/2
        property int startY: height/2
        property int endX: height/2
        property int endY: container.height - width/2

        x: startX - width/2
        y: startY - height/2

        text: "^"
        width: container.width/2; height: container.height/2

        onClicked: container.angle = (container.angle==0 ? -90 : 0)
    }


    states: [
        State {
            name: "normal"
            when: container.angle == 0
        },
        State {
            name: "rotated"
            when: container.angle == -90
        }
    ]

    state: "normal"

    transitions: [
        Transition {
            from: "normal"; to: "rotated"
            PathAnimation {
                duration: container.duration
                easing.type: Easing.InOutQuad

                target: button
                orientation: PathAnimation.LeftFirst
                anchorPoint: Qt.point(button.width/2, button.height/2)

                path: Path {
                    startX: button.startX; startY: button.startY

                    PathQuad {
                        x: button.endX
                        y: button.endY

                        controlX: x; controlY: button.startY
                    }
                }
            }
        },
        Transition {
            from: "rotated"; to: "normal"
            PathAnimation {
                duration: container.duration
                easing.type: Easing.InOutQuad

                target: button
                orientation: PathAnimation.RightFirst
                anchorPoint: Qt.point(button.width/2, button.height/2)

                path: Path {
                    startX: button.endX; startY: button.endY

                    PathQuad {
                        x: button.startX
                        y: button.startY

                        controlX: button.endX; controlY: y
                    }
                }
            }
        }
    ]
}
