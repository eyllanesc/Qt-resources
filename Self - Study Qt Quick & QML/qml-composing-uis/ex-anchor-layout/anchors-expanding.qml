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
    width: 300; height: 50
    color: "black"

    TextInput {
        id: textInput
        text: qsTr("Text input"); color: "white"
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.4 : parent.height * 0.4 }
        focus: true
        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        color: "red"
        anchors.left: textInput.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        height: 8
    }
}
