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
    width: 400; height: 200; color: "lightblue"

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
        hue: 0.8
    }

    FastBlur {
        anchors.fill: colorizeEffect
        source: colorizeEffect
        radius: 10.0
    }
}
