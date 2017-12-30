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
    property int size: 200
    property TouchPoint point

    width:size; height: size
    x: point.x - size/2
    y: point.y - size/2

    visible: point.pressed
}
