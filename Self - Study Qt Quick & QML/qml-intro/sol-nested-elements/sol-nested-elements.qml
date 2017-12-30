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
    color: "gray"

    Rectangle {
        x: 50; y: 50
        width: parent.width * 0.75; height: parent.height * 0.375
        color: "lightblue"

        Rectangle {
            x: 50; y: 50
            width: parent.width / 6.0; height: parent.height / 3.0
            color: "white"
        }
    }

    Rectangle {
        x: 50; y: 200
        width: parent.width * 0.75; height: parent.height * 0.375
        color: "green"

        Rectangle {
            x: 100; y: 50
            width: parent.width * 0.5; height: parent.width * 0.2
            color: "blue"
        }
    }
}
