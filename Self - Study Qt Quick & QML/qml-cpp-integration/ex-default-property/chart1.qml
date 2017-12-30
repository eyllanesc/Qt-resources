/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import Shapes 8.0
import QtQuick.Window 2.0

Window {
    visible: true
    width: 120; height: 120

    Chart {
        anchors.fill: parent

        Bar { color: "#a00000"
            value: -20 }
        Bar { color: "#00a000"
            value: 50 }
        Bar { color: "#0000a0"
            value: 100 }
    }
}


