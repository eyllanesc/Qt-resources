/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("SwipeView")

    header: Label {
        horizontalAlignment: Qt.AlignHCenter
        text: qsTr("This is a header")
    }
    footer: TabBar {
        id: tabBar
        TabButton {
            text: qsTr("Open a popup 1")
            onClicked: popup.open();
        }
    }
    Popup { id: popup
        width: parent.width * 0.5; height: parent.height * 0.5
        x: (parent.width - width) / 2; y: (parent.height - height) / 2
        modal: true
        Text {
            anchors.centerIn: parent
            text: qsTr("Text in popup")
        }
    }
    SwipeView {
        id: swipeView
        anchors { top: parent.top; bottom: indicator.top; left: parent.left; right: parent.right }
        currentIndex: tabBar.currentIndex
        Page1 {
        }
        Page2 {
        }
    }
    PageIndicator {
        id: indicator
        count: swipeView.count
        currentIndex: swipeView.currentIndex
        anchors.bottom: tabBar.top;
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
