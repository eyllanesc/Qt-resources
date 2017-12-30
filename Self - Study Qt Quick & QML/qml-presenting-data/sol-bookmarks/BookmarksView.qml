/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

ListView {
    anchors.left: parent.left
    anchors.right: parent.right

    clip: true
    focus: true

    delegate: Rectangle {
        color: (index % 2) ? Qt.rgba(0.75,0.75,0.75,0.5) : Qt.rgba(0.5,0.5,0.5,0.5)
        width: parent.width
        height: 32
        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 4
            font.pixelSize: 24
            text: title
        }
    }
    highlight: Rectangle {
        color: Qt.rgba(1,0,0,0.5)
        width: parent.width
        height: 32
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.focus = true
    }
}
