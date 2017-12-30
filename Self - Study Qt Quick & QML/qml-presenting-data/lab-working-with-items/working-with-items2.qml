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
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: addField.top

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
    
    Item {
        id: addField
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 4
        height: 32

        Text {
            id: label
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            text: "Item:"
            font.pixelSize: 20
            font.bold: false
        }
        Rectangle {
            anchors.left: label.right
            anchors.leftMargin: 8
            anchors.right: addButton.left
            anchors.rightMargin: 8
            anchors.verticalCenter: parent.verticalCenter

            color: "white"
            border.color: "gray"
            height: 24

            TextInput {
                id: lineEdit
                anchors.fill: parent
                anchors.margins: 2
                text: "Gitorious"
                font.pixelSize: parent.height - 4
            }
        }
        Button {
            id: addButton
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            text: "Add item"
            color: "#90c090"
        }
    }
}
