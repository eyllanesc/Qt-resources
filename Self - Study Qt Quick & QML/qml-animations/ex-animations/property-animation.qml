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
    width: 400; height: 400; color: "lightblue"

    Image {
        id: image
        x: parent.width * 0.25; y: parent.height * 0.25
        source: "../images/thumbnails.png"
    }

    PropertyAnimation {
        target: image
        properties: "width,height"
        from: 0; to: root.width * 0.5; duration: 1000
        running: true
    }
}
