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
    property alias text: output.text

    color: "transparent"
    border.color: "transparent"

    BorderImage {
        anchors.fill: parent
        border { left: 5; top: 5; right: 5; bottom: 6 }
        horizontalTileMode: BorderImage.Stretch
        verticalTileMode: BorderImage.Stretch
        source: "../images/textoutput.png"
    }

    TextEdit {
        id: output
        anchors { margins: 3; fill: parent }
        selectionColor: "transparent"
    }
}
