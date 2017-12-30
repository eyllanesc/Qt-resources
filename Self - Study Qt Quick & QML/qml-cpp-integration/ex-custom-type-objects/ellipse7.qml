/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import Shapes 7.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300; height: 150
    Row {
        anchors.fill: parent

        Ellipse {
            width: parent.width / 2; height: parent.height
            style: Style { color: "blue"
                filled: false }
        }

        Ellipse {
            width: parent.width / 2; height: parent.height
            style: Style { color: "darkgreen"
                filled: true }
        }
    }
}

