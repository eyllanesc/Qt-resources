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
        anchors.right: navigationButtons.left
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

        MouseArea {
            anchors.fill: parent
            onClicked: parent.focus = true
        }
    }
    
    Rectangle {
        id: navigationButtons
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: addField.top
        width: childrenRect.width + 16

        Column {
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.topMargin: 8
            anchors.top: parent.top
            spacing: 8

            Button {
                color: "#9090c0"
                text: "Move item up"
                onClicked: {
                    if (listView.currentIndex > 0)
                        bookmarkModel.move(listView.currentIndex,
                                           listView.currentIndex - 1, 1);
                }
            }

            Button {
                color: "#c09090"
                text: "Remove item"
                onClicked: {
                    if (listView.currentIndex != -1)
                        bookmarkModel.remove(listView.currentIndex);
                }
            }

            Button {
                color: "#c0c090"
                text: "Move item down"
                onClicked: {
                    if (listView.currentIndex < listView.count - 1)
                        bookmarkModel.move(listView.currentIndex,
                                           listView.currentIndex + 1, 1);
                }
            }
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
            onClicked: bookmarkModel.append({"title": lineEdit.text})
        }
    }
}
