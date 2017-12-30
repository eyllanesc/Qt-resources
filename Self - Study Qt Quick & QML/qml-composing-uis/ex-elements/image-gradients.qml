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
    property real margin: 25
    width: 425; height: 200

    Image {
        id: image1
        width: (parent.width - margin) / 2
        height: parent.height
        source: "../images/vertical-gradient.png"
    }

    Image {
        x: image1.width + margin; y: 0
        width: (parent.width - margin) / 2
        height: parent.height
        source: "../images/diagonal-gradient.png"
    }
}
