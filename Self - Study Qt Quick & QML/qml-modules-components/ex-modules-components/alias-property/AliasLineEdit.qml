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
    border.color: "green"
    color: "white"
    radius: 4; smooth: true
    clip: true

    TextInput {
        id: textInput
        anchors.fill: parent
        anchors.margins: 2
        text: qsTr("Enter text...")
        color: focus ? "black" : "gray"
        font.pixelSize: parent.height - 4
    }

    property alias text: textInput.text
}
