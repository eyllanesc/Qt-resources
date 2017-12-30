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
    width: 400; height: 200

    Image {
        anchors.fill: parent
        source: "../images/bluebackground.png"
    }

    BorderImage {
        id: borderImage1
        source: "../images/bluebutton.png"
        border { left: 13; top: 13; right: 13; bottom: 13 }
        anchors { top: parent.top; topMargin: 15; left: parent.left; leftMargin: 15; right: parent.right; rightMargin: 15 }
        Image {
            id: loginImage
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/login.png"
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: -20
            anchors.verticalCenter: parent.verticalCenter
            text: qsTr("Login")
            font.bold: true
            color:"white"
            font.pixelSize: 32
        }
    }

    BorderImage {
        source: "../images/bluebutton.png"
        border { left: 13; top: 13; right: 13; bottom: 13 }
        anchors { top: borderImage1.bottom; topMargin: 15; left: parent.left; leftMargin: 15; right: parent.right; rightMargin: 15 }
        Image {
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/signout.png"
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: -20
            anchors.verticalCenter: parent.verticalCenter
            text: qsTr("Sign Out")
            font.bold: true
            color:"white"
            font.pixelSize: 32
        }
    }
}
