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
        Text {
            text: name
            font.pixelSize: 32
        }
    }

    ListView {
        id: listView

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.rightMargin: 4
        width: parent.width/2

        onCurrentItemChanged: detailsAnimation.start()

        model: nameModel
        delegate: nameDelegate
        focus: true
        clip: true

        header: Rectangle {
            width: parent.width; height: 10;
            color: "pink"
        }
        footer: Rectangle {
            width: parent.width; height: 10;
            color: "lightblue"
        }
        highlight: Rectangle {
            width: parent.width; height: 10;
            color: "lightgray"
        }
    }

    Item {
        id: details
        anchors.left: listView.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        NumberAnimation on opacity {
            id: detailsAnimation
            from: 0.0; to: 1.0
            duration: 500
        }

        Item {
            width: parent.width
            height: picture.height + label.height
            anchors.centerIn: parent

            Image {
                id: picture
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: label.top
                width: details.width - 24
                height: width
                source: listView.model.get(listView.currentIndex).file
                fillMode: Image.PreserveAspectFit
                smooth: true
            }
            Text {
                id: label
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                text: "<b>" + listView.model.get(listView.currentIndex).name + "</b>"
                font.pixelSize: 24
            }
        }
    }
}
