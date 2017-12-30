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
        x: 0.25 * parent.width; y: 0.25 * parent.height
        width: parent.width / 2; height: parent.height / 2
        gradient: blueGreenGradient
    }

    Gradient {
        id: blueGreenGradient
        GradientStop { position: 0.0; color: "green" }
        GradientStop { position: 1.0; color: "blue" }
    }
}
