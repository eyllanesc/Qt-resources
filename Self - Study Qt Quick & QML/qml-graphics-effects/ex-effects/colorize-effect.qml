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
    width: 200; height: 500; color: "black"

    Image {
        id: image1; x: 30; y: 30
        source: "../images/rocket.svg"
    }

    Image {
        id: image2; x: 50; y: 185; visible: false
        source: "../images/rocket.svg"
    }

    Colorize {
        anchors.fill: image2
        source: image2
        hue: 0.6
        saturation: 0.5
    }

    Image {
        id: image3; x: 70; y: 340; visible: false
        source: "../images/rocket.svg"
    }

    Colorize {
        anchors.fill: image3
        source: image3
        hue: 0.6
        saturation: 1.0
    }
}
