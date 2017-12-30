/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.4
import Shapes 6.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300; height: 150
    Row {
        anchors.fill: parent

        Ellipse {
            width: parent.width / 2; height: parent.height
            color: "blue"
            style: Ellipse.Outline
        }

        Ellipse {
            width: parent.width / 2; height: parent.height
            color: "blue"
            style: Ellipse.Filled
        }
    }
}
