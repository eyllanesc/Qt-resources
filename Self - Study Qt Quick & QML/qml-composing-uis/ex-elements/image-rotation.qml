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
    width: 200; height: 200
    color: "black"

    Image {
        x: (parent.width - width) / 2; y: (parent.height - height) / 2
        source: "../images/rocket.png"
        rotation: 45.0
    }
}
