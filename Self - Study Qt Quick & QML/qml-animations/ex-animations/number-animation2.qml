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

    Rectangle {
        id: rect
        x: 0; y: parent.height * 0.375; width: parent.width * 0.25; height: width
    }

    NumberAnimation {
        target: rect
        properties: "x"
        from: 0; to: root.width * 0.375; duration: 1000
        running: true
    }
}
