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
    // The parent element
    width: 400; height: 400
    color: "lightblue"

    Text {
        text: qsTr("Centered text"); color: "green"
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
        anchors.centerIn: parent
    }
}
