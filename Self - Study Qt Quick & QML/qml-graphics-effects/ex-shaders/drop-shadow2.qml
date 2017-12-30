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
    width: 600; height: 600

    DropShadow {
        anchors.centerIn: parent
        width: source.width; height: source.height

        source: Image {
            source: "../images/butterfly.png"
            smooth: true
        }

        color: Qt.rgba(0, 0, 0, 0.3)
        samples: 32
        radius: 8

        horizontalOffset: offset.x
        verticalOffset: offset.y

        property real angle: 0
        property variant offset: Qt.point(15.0 * Math.cos(angle), 15.0 * Math.sin(angle))

        NumberAnimation on angle { loops: Animation.Infinite; from: 0; to: Math.PI * 2; duration: 6000 }
    }
}
