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
    width: 200; height: 200

    ListModel {
        id: nameModel
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Harry" }
        ListElement { name: "Jane" }
        ListElement { name: "Karen" }
        ListElement { name: "Lionel" }
        ListElement { name: "Victor" }
        ListElement { name: "Wendy" }
    }

    Component {
        id: nameDelegate
        Text {
            text: name;
            font.pixelSize: 32
        }
    }

    Rectangle {
        anchors.fill: parent
        border.color: "black"

        ListView {
            id: listView
            anchors.fill: parent
            anchors.margins: 4
            model: nameModel
            delegate: nameDelegate
            focus: true
            clip: true
            header: Rectangle {
                color: "pink"
                width: parent.width
                height: 8
            }
            highlight: Rectangle {
                color: "lightblue"
                width: parent.width
            }
            preferredHighlightBegin: 42
            preferredHighlightEnd: 150
            highlightRangeMode: ListView.ApplyRange

            Rectangle {
                color: "red"
                x: 0; y: parent.preferredHighlightBegin
                width: parent.width; height: 1
            }

            Rectangle {
                color: "red"
                x: 0; y: parent.preferredHighlightEnd
                width: parent.width; height: 1
            }
        }
    }
}
