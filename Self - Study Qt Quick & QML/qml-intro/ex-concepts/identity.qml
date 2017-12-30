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
    width: 300; height: 115

    Text {
        id: title
        x: 50; y: 25
        text: "Qt Quick"
        font { family: "Helvetica"; pointSize: parent.width * 0.1 }
    }

    Rectangle {
        x: title.x; y: title.y + title.height - height; height: 5
        width: title.width
        color: "green"
    }
}
