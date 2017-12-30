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
    width: 600; height: 600
    color: "azure"

    Canvas {
        anchors.fill: parent

        onPaint: {
            var context = getContext("2d");
            context.clearRect(0, 0, width, height);

            context.fillRule = Qt.OddEvenFill;
            context.fillStyle = "forestgreen";
            context.beginPath();
            context.moveTo(width * 0.1, height * 0.1);
            context.bezierCurveTo(width * 0.9, width * 0.1, width * 0.1, height * 0.9, height * 0.9, height * 0.9);
            context.bezierCurveTo(width * 0.9, width * 0.1, width * 0.1, height * 0.9, height * 0.1, height * 0.1);

            context.closePath();
            context.rect(width * 0.2, height * 0.2, width * 0.6, height * 0.6);
            context.fill();
        }
    }
}

