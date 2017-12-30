/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtGraphicalEffects 1.0

Rectangle {
    width: 400; height: 400
    color: "lightblue"

    Image {
        id: image
        anchors.centerIn: parent
        visible: false
        source: "../images/rocket.svg"
    }

    Colorize {
        id: colorizeEffect
        anchors.fill: image
        source: image
        visible: false
        SequentialAnimation on hue {
            loops: Animation.Infinite
            NumberAnimation {
                from: 0.0
                to: 1.0
                duration: 2500
            }
            NumberAnimation {
                from: 1.0
                to: 1.0
                duration: 2500
            }
        }
    }

    DirectionalBlur {
        anchors.fill: colorizeEffect
        source: colorizeEffect
        angle: 0
        samples: 24
        SequentialAnimation on length {
            loops: Animation.Infinite
            NumberAnimation {
                from: 0
                to: 32
                duration: 2500
            }
            NumberAnimation {
                from: 32
                to: 0
                duration: 2500
            }
        }
    }
}
