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
    width: 300; height: 200; color: "white"

    ListModel {
        id: nameModel
        ListElement { name: "Alice"; file: "../images/star.svg" }
        ListElement { name: "Bob"; file: "../images/night.svg" }
        ListElement { name: "Jane"; file: "../images/star.svg" }
        ListElement { name: "Harry"; file: "../images/star.svg" }
        ListElement { name: "Wendy"; file: "../images/night.svg" }
    }

    Component {
        id: nameDelegate
        Item {
            id: delegateItem
            width: parent.width
            height: 28

            Text {
                text: name
                font.pixelSize: parent.height - 4
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
            Image {
                source: file
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize: Qt.size(64,64)

                width: height; height: parent.height - 4
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    ListView {
        id: listView
        anchors.fill: parent

        model: nameModel
        delegate: nameDelegate
        focus: true
        clip: true

        header: Rectangle {
            width: parent.width; height: 10;
            color: "#8080ff"
        }
        footer: Rectangle {
            width: parent.width; height: 10;
            color: "#8080ff"
        }
        highlight: Rectangle {
            width: parent.width; height: 10;
            color: "lightgray"
        }
    }
}
