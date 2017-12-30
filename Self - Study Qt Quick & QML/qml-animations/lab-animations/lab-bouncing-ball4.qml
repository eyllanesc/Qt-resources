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
        source: "images/ball.png"

        NumberAnimation on x {
            from: 20; to: root.width * 0.83
            easing.type: "OutQuad"
            duration: 1250
        }

        SequentialAnimation on y {
            NumberAnimation {
                from: root.height * 0.67; to: 20
                easing.type: "OutQuad"
                duration: 250
            }

            NumberAnimation {
                from: 20; to: root.height * 0.67
                easing.type: "OutBounce"
                duration: 1000
            }
        }

        RotationAnimation on rotation {
            from: 0; to: 360
            direction: RotationAnimation.Clockwise
            duration: 1000
        }
    }
}

