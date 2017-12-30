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
    id: container

    signal clicked

    property string text

    Rectangle {
        id: background
        anchors.fill: parent
        border.color: mouseRegion.pressed ? "gray" : "black"
        smooth: true
        radius: 10
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#606060" }
            GradientStop { position: 0.33; color: "#202020" }
            GradientStop { position: 1.0; color: "#404040" }
        }
    }
    Text {
        color: "white"
        anchors.centerIn: background; font.bold: true; font.pixelSize: 15
        text: container.text; style: Text.Raised; styleColor: "black"
    }
    MouseArea {
        id: mouseRegion
        anchors.fill: parent
        onClicked: container.clicked()
    }
}
