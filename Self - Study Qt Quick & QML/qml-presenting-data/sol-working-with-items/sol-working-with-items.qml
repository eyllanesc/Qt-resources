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

    BookmarksView {
        id: listView
        anchors.left: parent.left
        anchors.right: navigationPanel.left
        anchors.top: parent.top
        anchors.bottom: addField.top

        model: bookmarkModel
    }
    
    NavigationPanel {
        id: navigationPanel
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: addField.top

        onMoveUpClicked: {
            if (listView.currentIndex > 0)
                bookmarkModel.move(listView.currentIndex,
                                   listView.currentIndex - 1, 1);
        }

        onRemoveClicked: {
            if (listView.currentIndex != -1)
                bookmarkModel.remove(listView.currentIndex);
        }

        onMoveDownClicked: {
            if (listView.currentIndex < listView.count - 1)
                bookmarkModel.move(listView.currentIndex,
                                   listView.currentIndex + 1, 1);
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
