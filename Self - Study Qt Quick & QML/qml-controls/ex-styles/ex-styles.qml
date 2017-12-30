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
    title: qsTr("Controls")

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

    GridLayout {
        anchors.fill: parent
        columns: 3
        Button {
            id: button
            text: qsTr("Press me")
            onClicked: popup.open();
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                color: button.down ? "#d6d6d6" : "#f6f6f6"
                border.color: "#26282a"
                border.width: 1
                radius: 4
            }
        }
        RadioButton {
        }
        Label {
            text: qsTr("I'm a label")
        }
        Slider {
            id: slider
            from: -10
            to: 10
            value: 0
            background: Rectangle {
                x: slider.leftPadding
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: slider.availableWidth
                height: implicitHeight
                radius: 2
                color: "#bdbebf"

                Rectangle {
                    width: slider.visualPosition * parent.width
                    height: parent.height
                    color: "#21be2b"
                    radius: 2
                }
            }

            handle: Rectangle {
                x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 26
                implicitHeight: 26
                radius: 13
                color: slider.pressed ? "#f0f0f0" : "#f6f6f6"
                border.color: "#bdbebf"
            }
        }
        SpinBox {
            from: -10
            to: 10
            value: slider.value
        }
        BusyIndicator {
            running: true
            MouseArea {
                anchors.fill: parent
                onClicked: (parent.running) ? parent.running = false : parent.running = true
            }
        }
        ProgressBar {
            value: 0.48
        }
        TextField {
            validator: IntValidator {
                bottom: 11; top: 31;
            }
            focus: true
        }
    }
}


