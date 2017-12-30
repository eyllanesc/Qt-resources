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

Item {
    property real margin: 20
    width: 1300
    height: 200

    Rectangle {
        width: parent.width * 0.33 - margin; height: parent.height
        color: "lightblue"
        Text {
            id: textElement1
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.verticalCenter
            text: qsTr("Qt Quick")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
        }

        DropShadow {
            anchors.fill: textElement1
            source: textElement1
            radius: 8.0
            samples: 16
            color: "darkblue"
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            text: qsTr("radius 8\nsamples: 16")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "darkBlue"
        }
    }

    Rectangle {
        x: parent.width * 0.33 + margin
        width: parent.width * 0.33 - margin; height: parent.height
        color: "lightblue"
        Text {
            id: textElement2
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.verticalCenter
            text: qsTr("Qt Quick")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
        }

        DropShadow {
            anchors.fill: textElement2
            source: textElement2
            radius: 16.0
            samples: 16
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            text: qsTr("radius 16\nsamples: 16")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "darkBlue"
        }
    }

    Rectangle {
        x: (parent.width * 0.33 + margin) * 2
        width: parent.width * 0.33 - margin; height: parent.height
        color: "lightblue"
        Text {
            id: textElement3
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.verticalCenter
            text: qsTr("Qt Quick")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
        }

        DropShadow {
            anchors.fill: textElement3
            source: textElement3
            radius: 16.0
            horizontalOffset: -8
            samples: 16
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            text: qsTr("radius 16\nsamples: 16\nhorizontalOffset: -8")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "darkBlue"
        }
    }
}
