/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400; height: 300

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightblue" }
            GradientStop { position: 1.0; color: "lightgray" }
        }
    }

    id: root

    Component {
        id: nameDelegate
        Text {
            color: Qt.rgba(0.5 + 0.5 * Math.sin(root.component + index * Math.PI/8),
                           0.5 + 0.5 * Math.sin(root.component + 0.5 * Math.PI + index * Math.PI/8),
                           0.5 + 0.5 * Math.sin(root.component + 1.5 * Math.PI + index * Math.PI/8), 1.0)
            text: lineEdit.text[index]
            font.pixelSize: 50
            y: wiggly.height/2 - font.pixelSize/2 + (Math.sin((index * Math.PI/4 + root.value)) * wiggly.height/8)
        }
    }

    Item {
        id: wiggly
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: lineEdit.top
        width: parent.width
        Row {
            Repeater {
                model: lineEdit.text.length
                delegate: nameDelegate
            }
        }
    }

    property real component: 0
    NumberAnimation on component {
        from: 0.0; to: 2.0 * Math.PI
        duration: 1000
        running: true
        loops: Animation.Infinite
    }

    property real value: 0
    NumberAnimation on value {
        from: 0.0; to: 2.0 * Math.PI
        duration: 1000
        running: true
        loops: Animation.Infinite
    }

    // Simple line editor

    Rectangle {
        id: lineEdit
        radius: 4
        anchors.topMargin: 32
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 32
        width: parent.width * 0.75
        height: input.font.pixelSize + 8
        color: "white"

        TextInput {
            id: input
            anchors.centerIn: parent
            width: parent.width - 8
            font.pixelSize: 32
        }
        
        property alias text: input.text
    }
}

