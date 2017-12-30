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
    width: textItem.width + checkImage.width

    Image {
        id: checkImage
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }
    
    Text {
        id: textItem
        anchors.left: checkImage.right
        anchors.leftMargin: 4
        anchors.verticalCenter: checkImage.verticalCenter
        text: "Option"
        font.pixelSize: checkImage.height - 4
    }

    states: [
        State {
            name: "checked"
            PropertyChanges { target: checkImage; source: "checked.svg" }
        },
        State {
            name: "unchecked"
            PropertyChanges { target: checkImage; source: "unchecked.svg" }
        }
    ]

    state: "unchecked"

    MouseArea {
        anchors.fill: checkImage
        onClicked: parent.state == "checked" ? parent.state = "unchecked"
                                             : parent.state = "checked"
    }
}
