/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import "content"

Item {
    id: screen; width: 534; height: 534
    property int animDuration: 500

    RotationButton {
        id: rotationButton
        duration: screen.animDuration
        z: 100
        anchors.top: screen.top
        anchors.left: screen.left
    }

    Rectangle {
        id: background
        anchors.centerIn: parent; color: "#555560";
        width: rotationButton.angle==0 ? parent.width : parent.height
        height: rotationButton.angle==0 ? parent.height : parent.width
        rotation: rotationButton.angle

        Behavior on rotation {
            RotationAnimation {
                duration: screen.animDuration
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on width {
            NumberAnimation {
                duration: screen.animDuration
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on height {
            NumberAnimation {
                duration: screen.animDuration
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on color {
            ColorAnimation {
                duration: screen.animDuration
                easing.type: Easing.InOutQuad
            }
        }

        Item {
            id: grid
            anchors.fill: parent

            function displayPicture(path) {
                picture.source = path
                screen.state = "displayPicture"
            }

            Thumbnail { column: 0; row: 0; image: "images/IMG_0985.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 1; row: 0; image: "images/IMG_1080.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 2; row: 0; image: "images/IMG_1524.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 3; row: 0; image: "images/IMG_1750.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 0; row: 1; image: "images/IMG_8536.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 1; row: 1; image: "images/IMG_8837.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 2; row: 1; image: "images/IMG_8955.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 3; row: 1; image: "images/IMG_9044.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 0; row: 2; image: "images/IMG_9077.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 1; row: 2; image: "images/IMG_9223.JPG"; onClicked: parent.displayPicture(image) }
            Thumbnail { column: 2; row: 2; image: "images/IMG_9440.JPG"; onClicked: parent.displayPicture(image) }
        }

        Image {
            id: picture
            z: 2
            x: 2 * parent.width; y: 0
            width: parent.width; height: parent.height
            smooth: true
            fillMode: Image.PreserveAspectFit
        }

        Button {
            id: backButton
            x: parent.width - width - 30
            y: parent.height + 3 * height
            z: 5
            width: 150
            height: 32

            text: "Back"
            onClicked: screen.state = "displayGrid"
            visible: false
        }
    }

    state: "displayGrid"

    states: [
        State {
            name: "displayGrid"
            PropertyChanges { target: background; color: "#555560" }
        },
        State {
            name: "displayPicture"
            PropertyChanges { target: background; color: "#101010" }
        }

    ]

    transitions: [
        Transition {
            from: "displayGrid"; to: "displayPicture"

            ParallelAnimation {
                PropertyAnimation { target: backButton; properties: "visible"; to: true }
                NumberAnimation {
                    target: grid
                    properties: "scale"; to: 0.5
                    duration: screen.animDuration
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: grid
                    properties: "opacity"; to: 0.0
                    duration: screen.animDuration
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: picture
                    properties: "x"; to: 0
                    duration: screen.animDuration
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: backButton
                    properties: "y"; to: background.height - backButton.height - 20
                    duration: screen.animDuration * 2
                    easing.type: Easing.OutBounce
                }
            }
        },
        Transition {
            from: "displayPicture"; to: "displayGrid"

            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation {
                        target: picture
                        properties: "x"; to: 2 * screen.width
                        duration: screen.animDuration
                        easing.type: Easing.InOutQuad
                    }
                    NumberAnimation {
                        target: backButton
                        properties: "y"; to: background.height + 3 * backButton.height
                        duration: screen.animDuration * 2
                        easing.type: Easing.InBack
                    }
                }
                PauseAnimation { duration: screen.animDuration / 2 }
                ParallelAnimation {
                    NumberAnimation {
                        target: grid
                        properties: "scale"; to: 1.0
                        duration: screen.animDuration
                        easing.type: Easing.InOutQuad
                    }
                    NumberAnimation {
                        target: grid
                        properties: "opacity"; to: 1.0
                        duration: screen.animDuration
                        easing.type: Easing.InOutQuad
                    }
                }
                PropertyAnimation { target: backButton; properties: "visible"; to: false }
            }
        }
    ]
}
