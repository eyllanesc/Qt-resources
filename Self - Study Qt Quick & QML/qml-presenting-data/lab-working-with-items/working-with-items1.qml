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
    width: 440; height: 300

    ListModel {
        id: bookmarkModel
        ListElement { title: "Qt" }
        ListElement { title: "Documentation" }
        ListElement { title: "Qt Developer Network" }
        ListElement { title: "Qt Labs" }
    }

    ListView {
        id: listView
        anchors.fill: parent

        clip: true
        focus: true
        model: bookmarkModel

        delegate: Rectangle {
            color: (index % 2) ? "#80c0c0c0" : "#80808080"
            width: parent.width
            height: 32
            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 4
                font.pixelSize: 24
                text: title
            }
        }
        highlight: Rectangle {
            color: "#80ff0000"
            width: parent.width
            height: 32
        }
    }
}
