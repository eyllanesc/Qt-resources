/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import Shapes 3.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300; height: 300
    Item {
        anchors.fill: parent
        Ellipse {
            id: ellipse
            anchors.fill: parent
            anchors.bottomMargin: label.height
            color: "blue"
            onReady: label.text = "Ready"
        }

        Text {
            id: label
            anchors { top: ellipse.bottom; horizontalCenter: parent.horizontalCenter }
            font { pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            text: "Not ready"
        }
    }
}
