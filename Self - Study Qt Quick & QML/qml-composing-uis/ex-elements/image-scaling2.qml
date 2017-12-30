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
    width: 400; height: 400
    color: "black"

    Image {
        x: (parent.width - width) / 2; y: (parent.height - height) / 2
        source: "../images/rocket.png"
        scale: 2.0
        transformOrigin: Item.Top
    }
}
