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
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Window")

    header: Label {
        horizontalAlignment: Qt.AlignHCenter
        text: qsTr("This is a header")
    }
    footer: TabBar {
        id: tabBar
        currentIndex: container.currentIndex
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
    Container {
        id: container
        contentItem: ListView {
            model: container.contentModel
        }
        Grid {
            id: grid
            property real imageWidth: 50
            columns: root.width / imageWidth

            Repeater {
                property int kakka: 7
                id: repeater
                model: 50
                Image { width: grid.imageWidth; height: width; source: "../images/butterfly.png" }
            }
        }
    }
}
