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
import Shapes 5.0

Window {
    visible: true
    width: 300
    height: 200

    Item {
        anchors.fill: parent

        Ellipse {
            id: ellipse
            anchors.fill: parent
            anchors.bottomMargin: label.height
            color: "blue"
            onReady: label.text = qsTr("Ready")

            MouseArea {
                anchors.fill: parent
                onClicked: parent.color = parent.randomColor()
            }
        }

        Text {
            id: label
            anchors { top: ellipse.bottom; horizontalCenter: parent.horizontalCenter }
            font { pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            text: qsTr("Not ready")
        }
    }
}

