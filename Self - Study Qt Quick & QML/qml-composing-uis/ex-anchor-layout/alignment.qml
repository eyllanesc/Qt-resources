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
    color: "lightblue"

    Image { id: book; source: "../images/book.svg"
        anchors.left: parent.left
        anchors { leftMargin: parent.width / 16
            verticalCenter: parent.verticalCenter }
    }

    Text { text: qsTr("Writing"); font.pixelSize: 32
        anchors { left: book.right; leftMargin: 32;
            baseline: book.verticalCenter }
    }
}
