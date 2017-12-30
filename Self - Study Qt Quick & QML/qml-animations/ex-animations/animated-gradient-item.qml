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
    width: 400; height: 400

    Rectangle {
        NumberAnimation on x { from: 0; to: 100; duration: 1000 }
        NumberAnimation on y { from: 0; to: 100; duration: 1000 }
        width: 200; height: 200
        gradient: blueGreenGradient
    }

    Gradient {
        id: blueGreenGradient
        GradientStop { position: 0.0; color: "green" }
        GradientStop { position: 1.0; color: "blue" }
    }
}
