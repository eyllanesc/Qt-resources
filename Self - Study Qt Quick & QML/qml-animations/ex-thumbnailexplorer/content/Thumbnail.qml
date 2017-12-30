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

    property int column
    property int row
    property string image

    x: 32 + column * (width + 32)
    y: 32 + row * (width + 32)
    width: 96
    height: 96

    Rectangle { color: "black"; anchors.fill: parent }
    Rectangle { x: 4; y: 4; width: parent.width-8; height: parent.height-8; color: "white"; smooth: true }
    Image {
        x: 5; y: 5
        width: parent.width-10
        height: parent.height-10

        source: "../"+container.image
        fillMode: Image.PreserveAspectCrop
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
