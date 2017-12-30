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
    width: 600; height: 600

    Canvas {
        property int radius: width/2 - 10

        property int dataCount: 7
        property var data: []
        property var colors: []
        property int total: 0

        function randomValue() {
            return Math.round(400 * Math.random())
        }

        function randomColor() {
            var rgb = []
            for (var i = 0; i < 3; i++) {
                rgb[i] = Math.round(100 * Math.random() + 155) / 255
            }
            return Qt.rgba(rgb[0], rgb[1], rgb[2])
        }

        anchors.centerIn: parent
        width: Math.min(parent.width, parent.height)
        height: width
        smooth: true

        Component.onCompleted: {
            for (var i=0; i<dataCount; i++) {
                data[i] = randomValue();
                colors[i] = randomColor();
                total+= data[i];
            }
            requestPaint();
        }

        onPaint: {
            var context = getContext("2d")
            context.clearRect(0, 0, width, height);

            var angleOffset = 0;
            for (var i=0; i<data.length; i++) {
                var angle = Math.PI * 2 * data[i] / total;

                context.beginPath();
                context.arc(width/2, height/2, radius, angleOffset, angleOffset + angle);
                context.lineTo(width/2, height/2);
                context.closePath();

                context.strokeStyle = "black";
                context.stroke();

                context.fillStyle = colors[i];
                context.fill();

                angleOffset+= angle;
            }
        }
    }
}
