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
    width: 400; height: 300

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
        anchors.bottom: parent.bottom
        model: bookmarkModel
    }

    BookmarkEditor {
        onAddClicked: bookmarkModel.append({"title": title, "link": link})
        onRemoveClicked: {
            if (listView.currentIndex != -1)
                bookmarkModel.remove(listView.currentIndex);
        }
    }
}
