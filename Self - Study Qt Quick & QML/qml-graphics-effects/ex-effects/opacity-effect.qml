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
    width: 365; height: 200; color: "black"

    Image {
        id: image1
        opacity: 0.5
        x: 20; y: 30
        source: "../images/rocket.svg"
    }

    Image {
        id: image2
        opacity: 0.7
        x: 130; y: 30
        source: "../images/rocket.svg"
    }

    Image {
        id: image3
        opacity: 1.0
        x: 240; y: 30
        source: "../images/rocket.svg"
    }
}
