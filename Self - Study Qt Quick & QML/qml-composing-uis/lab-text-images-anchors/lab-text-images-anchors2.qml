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
    width: 400; height: 200

    Image {
        anchors.fill: parent
        source: "../images/bluebackground.png"
    }

    BorderImage {
        id: borderImage1
        source: "../images/bluebutton.png"
        border { left: 13; top: 13; right: 13; bottom: 13 }
        anchors { top: parent.top; topMargin: 15; left: parent.left; leftMargin: 15; right: parent.right; rightMargin: 15 }
    }

    BorderImage {
        source: "../images/bluebutton.png"
        border { left: 13; top: 13; right: 13; bottom: 13 }
        anchors { top: borderImage1.bottom; topMargin: 15; left: parent.left; leftMargin: 15; right: parent.right; rightMargin: 15 }
    }
}
