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
    width: 400; height: 300
    color: "#ffffe0"

    ListModel {
        id: bookmarkModel
        ListElement { title: "Qt"; link: "http://qt.nokia.com" }
        ListElement { title: "Documentation"; link: "http://doc.qt.nokia.com" }
        ListElement { title: "Qt Developer Network"; link: "http://developer.qt.nokia.com" }
        ListElement { title: "Qt Labs"; link: "http://labs.qt.nokia.com" }
    }

    Text {
        id: title
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Bookmarks"
        font.pixelSize: 32
    }

    BookmarksView {
        id: listView
        anchors.top: title.bottom
        anchors.bottom: bookmarkEditor.top
        model: bookmarkModel
    }

    Column {
        id: bookmarkEditor
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 4
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

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 8
            spacing: 8

            Button {
                text: "Add bookmark"
                color: "#90c090"
                onClicked: bookmarkModel.append({"title": titleField.text,
                                                 "link": urlField.text})
            }
            Button {
                color: "#c09090"
                text: "Remove bookmark"
                onClicked: {
                    if (listView.currentIndex != -1)
                        bookmarkModel.remove(listView.currentIndex);
                }
            }
        }
    }
}
