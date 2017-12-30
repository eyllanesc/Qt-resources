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
    id: root
    width: 1024; height: 600
    color: "steelblue"

    Image {
        source: "qt_logo.png"

        PinchArea {
            anchors.fill: parent
            pinch.target: parent

            pinch.minimumScale: 0.5
            pinch.maximumScale: 2.0

            pinch.minimumRotation: -3600
            pinch.maximumRotation: 3600

            pinch.dragAxis: Pinch.XAxis
        }
    }
 }
