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
    property alias text: label.text
    signal clicked

    radius: 5; smooth: true
    width: label.width + 16
    height: label.height + 4

    Text {
        id: label
        anchors.centerIn: parent
        text: ""
        font.pixelSize: 16
    }
    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
