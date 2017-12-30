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
    width: 1000
    height: 250

    Rectangle {
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            id: image1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            source: "../images/rocket.svg"
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter
            anchors.topMargin: 35
            text: qsTr("original")
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }

    Rectangle {
        x: parent.width * 0.33 + margin
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            id: image2
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            source: "../images/rocket.svg"
        }

        Colorize {
            anchors.fill: image2
            source: image2
            hue: 0.6
            saturation: 0.5
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter
            anchors.topMargin: 35
            text: qsTr('hue: "0.6"\nsaturation: 0.5')
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }

    Rectangle {
        x: (parent.width * 0.33 + margin) * 2
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            id: image3
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            source: "../images/rocket.svg"
        }

        Colorize {
            anchors.fill: image3
            source: image3
            hue: 0.6
            saturation: 1.0
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter
            anchors.topMargin: 35
            text: qsTr('hue: "0.6"\nsaturation: 1.0')
            font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }
}
