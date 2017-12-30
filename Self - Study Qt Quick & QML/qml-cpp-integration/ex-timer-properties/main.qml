/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Window 2.0
import CustomComponents 1.0

Window {
    visible: true
    width: 500
    height: 360

    Rectangle {
        anchors.fill: parent

        Timer {
            id: timer
            interval: 3000
        }

        Text {
            text: qsTr("Timer is running")
            font { pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60
        }
    }
}
