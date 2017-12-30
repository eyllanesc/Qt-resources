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
    width: 200; height: 220
    color: "darkred"
    
    Timer {
        id: timer
        interval: 1000
        repeat: true
        onTriggered: clock.marks = (clock.marks + 1) % 25
    }

    Item {
        id: clock
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.bottom: startButton.top
        anchors.bottomMargin: 4
        property int marks: 0
        
        Item {
            // We need an item wrapped around this one (holding the Repeater)
            // otherwise it's unclear which coordinate system is used.
            anchors.centerIn: parent
            Repeater {
                model: clock.marks
                Rectangle {
                    width: 10; height: 10
                    color: "white"
                    smooth: true
                    transform: [
                        Translate { y: -75 },
                        Rotation { angle: index * (360/24) }
                    ]
                    NumberAnimation on opacity {
                        from: (index == clock.marks - 1) ? 0.0 : 1.0; to: 1.0
                        duration: 1000
                        running: true
                    }
                }
            }
        }
    }

    Button {
        id: startButton
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        
        text: "Start"
        font.pixelSize: 24
        onClicked: {
            timer.start();
            stopButton.enabled = true;
            enabled = false;
            }
    }

    Button {
        id: stopButton
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        enabled: false
        
        text: "Stop"
        font.pixelSize: 24
        onClicked: {
            timer.stop();
            startButton.enabled = true;
            enabled = false;
            }
    }
}
