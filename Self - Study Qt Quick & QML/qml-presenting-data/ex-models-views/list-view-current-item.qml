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
    width: 150; height: 230; color: "white"

    ListModel {
        id: nameModel
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Harry" }
        ListElement { name: "Wendy" }
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

        width: parent.width
        anchors.top: parent.top
        anchors.bottom: label.top
        anchors.bottomMargin: 4

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
            width: parent.width
            color: "lightgray"
        }
    }

    Text {
        id: label
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "<b>" + listView.currentItem.text +
              "</b> is current"
        font.pixelSize: 16
    }
}
