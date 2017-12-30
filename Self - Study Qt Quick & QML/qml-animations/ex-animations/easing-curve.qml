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
    id: root
    width: 400; height: 400
    color: "lightblue"

    Image {
        x: parent.width * 0.55
        source: "../images/backbutton.png"
        NumberAnimation on y {
            from: 0; to: root.height * 0.875
            duration: 1000
            easing.type: "OutExpo"
        }
    }
}

