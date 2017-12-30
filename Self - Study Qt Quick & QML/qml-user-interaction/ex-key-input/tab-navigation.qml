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
    width: 200; height: 112; color: "lightblue"

    TextInput {
        id: nameField
        anchors { left: parent.left; leftMargin: 16 }
        anchors.right: parent.right
        text: qsTr("Name: ")
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.3 : parent.height * 0.3 }
        color: focus ? "black" : "gray"
        focus: true
        KeyNavigation.tab: addressField
    }
    TextInput {
        id: addressField
        anchors { left: parent.left; leftMargin: 16 }
        anchors.right: parent.right
        anchors.top: nameField.bottom
        text: qsTr("Address: ")
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.3 : parent.height * 0.3 }
        color: focus ? "black" : "gray"
        KeyNavigation.backtab: nameField

    }
}

