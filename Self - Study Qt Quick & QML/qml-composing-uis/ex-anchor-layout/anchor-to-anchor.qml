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
    width: 300; height: 200
    color: "lightblue"

    Text {
        y: 34
        text: qsTr("Right-aligned text"); color: "green"
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
        anchors.right: parent.right
    }
}
