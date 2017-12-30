/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Item {
    property real margin: 20
    width: 1000
    height: 250

    Rectangle {
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
            opacity: 0.5
            source: "../images/rocket.svg"
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 27
            text: qsTr("opacity: 0.5"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }

    Rectangle {
        x: parent.width * 0.33 + margin
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
            opacity: 0.7
            source: "../images/rocket.svg"
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 27
            text: qsTr("opacity: 0.7"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }

    Rectangle {
        x: (parent.width * 0.33 + margin) * 2
        width: parent.width * 0.33 - margin; height: parent.height
        color: "black"
        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
            source: "../images/rocket.svg"
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 27
            text: qsTr("(default) 1.0"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
            color: "white"
        }
    }
}
