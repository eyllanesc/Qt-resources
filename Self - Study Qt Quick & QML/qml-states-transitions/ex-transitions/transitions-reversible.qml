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
    width: 250; height: 50; color: "#ccffcc"

    TextInput {
        id: textField
        text: "Enter text..."
        font.pointSize: 24
        anchors { left: parent.left; leftMargin: 4
                  verticalCenter: parent.verticalCenter }
    }
    
    Image {
        id: clearButton
        source: "../images/clear.svg"
        anchors { right: parent.right; rightMargin: 4
                  verticalCenter: textField.verticalCenter }
        MouseArea {
            anchors.fill: parent
            onClicked: textField.text = ""
        }
    }

    states: [
      State {
        name: "with text"
        when: textField.text != ""
        PropertyChanges { target: clearButton; opacity: 1.0 }
      },
      State {
        name: "without text"
        when: textField.text == ""
        PropertyChanges { target: clearButton; opacity: 0.25 }
        PropertyChanges { target: textField; focus: true }
      }
    ]

    transitions: [
        Transition {
            from: "with text"; to: "without text"
            reversible: true
            PropertyAnimation {
                target: clearButton
                properties: "opacity"; duration: 1000
            }
        }
    ]
}
