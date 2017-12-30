/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtGraphicalEffects 1.0

Rectangle {
    width: 400
    height: 200
    color: "lightblue"

    Text {
        id: textElement
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Qt Quick"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
        visible: false
    }
    FastBlur { anchors.fill: textElement; radius: 32; source: textElement }
}
