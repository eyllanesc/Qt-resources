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
    id: bookmarkEdit
    anchors.left: parent.left
    anchors.right: parent.right

    signal addClicked(string title, string link)
    signal removeClicked

    y: parent.height - addBookmarkButton.height - 8
    height: 156

    color: Qt.rgba(0.9, 0.9, 0.7, 0.9)
    Column {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 8

        Row {
            id: buttons
            anchors.horizontalCenter: parent.horizontalCenter
            height: 24
            spacing: 8

            Button {
                id: addBookmarkButton
                color: "#90c090"
                text: "Add bookmark..."
                onClicked: {
                    if (bookmarkEdit.state == "default")
                        bookmarkEdit.state = "add bookmark";
                    else
                        bookmarkEdit.state = "default";
                }
            }

            Button {
                color: "#c09090"
                text: "Remove bookmark"
                onClicked: bookmarkEdit.removeClicked()
            }
        }

        Column {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 4

            InputField {
                id: titleField
                title: "Title"
                text: "[Title]"
            }

            InputField {
                id: urlField
                title: "URL"
                text: "http://"
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Add"
                color: "#90c090"
                onClicked: bookmarkEdit.addClicked(titleField.text, urlField.text)
            }
        }
    }

    states: [
        State {
            name: "add bookmark"
            PropertyChanges { target: bookmarkEdit
                              y: parent.height - height }
            PropertyChanges { target: addBookmarkButton
                              color: "lightgray" }
            PropertyChanges { target: addBookmarkButton
                              text: "Hide" }
        },
        State {
            name: "default"
        }
    ]

    transitions: Transition {
        NumberAnimation {
            target: bookmarkEdit
            property: "y"
            easing.type: "OutQuad"
            duration: 300
        }
    }
    state: "default"
}
