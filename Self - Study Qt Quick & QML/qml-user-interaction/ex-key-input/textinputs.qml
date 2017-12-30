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
        id: textInput1
        anchors { left: parent.left; leftMargin: 16 }
        anchors.right: parent.right
        text: qsTr("Field 1")
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.4 : parent.height * 0.4 }
        color: focus ? "black" : "gray"
        focus: true
    }
    TextInput {
        anchors { left: parent.left; leftMargin: 16 }
        anchors.right: parent.right
        anchors.top: textInput1.bottom
        text: qsTr("Field 2")
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.4 : parent.height * 0.4 }
        color: focus ? "black" : "gray"
    }
}

