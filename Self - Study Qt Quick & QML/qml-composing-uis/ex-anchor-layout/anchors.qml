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
    color: "lightblue"
    id: rectangle1

    Text {
        text: "Centered text"; color: "green"
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
        anchors.centerIn: rectangle1
    }
}
