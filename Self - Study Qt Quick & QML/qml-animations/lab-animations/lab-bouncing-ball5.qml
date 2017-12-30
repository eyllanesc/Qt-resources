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
    width: 600; height: 300

    Image {
        id: ball
        source: "images/ball.png"

        ParallelAnimation {
            running: true

            NumberAnimation {
                from: 20; to: root.width * 0.83
                easing.type: "OutQuad"
                target: ball
                property: "x"
                duration: 1250
            }

            SequentialAnimation {
                NumberAnimation {
                    from: root.height * 0.67; to: 20
                    easing.type: "OutQuad"
                    target: ball
                    property: "y"
                    duration: 250
                }

                NumberAnimation {
                    from: 20; to: root.height * 0.67
                    easing.type: "OutBounce"
                    duration: 1000
                    target: ball
                    property: "y"
                }
            }

            RotationAnimation {
                from: 0; to: 360
                direction: RotationAnimation.Clockwise
                duration: 1000
                target: ball
                property: "rotation"
            }
        }
    }
}

