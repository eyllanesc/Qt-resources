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
    border.color: "blue"
    color: "white"
    radius: 8; smooth: true
    clip: true

    TextInput {
        anchors.fill: parent
        anchors.margins: 4
        text: qsTr("Enter text...")
        color: focus ? "black" : "gray"
        font.pixelSize: parent.height - 8
    }
}
