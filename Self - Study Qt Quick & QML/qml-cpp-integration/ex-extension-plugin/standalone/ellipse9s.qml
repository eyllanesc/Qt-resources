/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Item {
    property real margin: 20
    width: 300; height: 200

    Ellipse {
        anchors { fill: parent; margins: margin }
    }
}
