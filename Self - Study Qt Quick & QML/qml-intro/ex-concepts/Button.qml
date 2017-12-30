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
    property bool enabled: true
    property alias text: label.text
    property alias font: label.font
    signal clicked()

    width: label.width + 32
    height: label.height + 2
    radius: 4
    color: "#d0d0d0"
    opacity: enabled ? 1.0 : 0.5

    Text {
        id: label
        font.family: "Helvetica"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: parent.enabled
        onClicked: if (parent.enabled) parent.clicked();
        onEntered: if (parent.enabled) parent.color = "#c0c0c0"
        onExited: if (parent.enabled) parent.color = "#d0d0d0"
        onPressed: if (parent.enabled) parent.color = "#a0a0a0"
        onReleased: if (parent.enabled) parent.color = "#c0c0c0"
    }
}
