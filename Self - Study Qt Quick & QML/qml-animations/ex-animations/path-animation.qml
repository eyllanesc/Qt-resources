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
    id: window
    width: 320; height: 480; color: "#000040"

    Canvas {
        id: canvas
        anchors.fill: parent
        smooth: true

        onPaint: {
            var context = canvas.getContext("2d")
            context.clearRect(0, 0, width, height)
            context.strokeStyle = "white"
            context.path = pathAnim.path
            context.stroke()
        }
    }

    Item {
        id: rocket
        x: 0; y: 0
        width: 128; height: 96

        Image {
            source: "../images/rocket.png"
            anchors.centerIn: parent
            rotation: 90
        }

        MouseArea {
            anchors.fill: parent
            onClicked: pathAnim.running ? pathAnim.stop() : pathAnim.start()
        }
    }

    PathAnimation {
        id: pathAnim
        duration: 2000
        easing.type: Easing.InOutQuad

        target: rocket
        orientation: PathAnimation.RightFirst
        anchorPoint: Qt.point(rocket.width/2, rocket.height/2)

        path: Path {
            startX: rocket.width/2; startY: rocket.height/2

            PathCubic {
                x: window.width - rocket.width/2
                y: window.height - rocket.height/2

                control1X: x; control1Y: rocket.height/2
                control2X: rocket.width/2; control2Y: y
            }
        }
    }
}
