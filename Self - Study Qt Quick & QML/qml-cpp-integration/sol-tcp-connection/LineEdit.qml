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
    signal textEntered(string text)

    height: entryField.height+6
    color: "transparent"
    border.color: "transparent"
    anchors { rightMargin: 0; leftMargin: 0; bottomMargin: 0 }

    BorderImage {
        anchors.fill: parent
        border { left: 5; top: 5; right: 5; bottom: 6 }
        horizontalTileMode: BorderImage.Stretch
        verticalTileMode: BorderImage.Stretch
        source: "../images/textinput.png"
    }

    TextInput {
        id : entryField
        anchors { margins: 3; fill: parent }
        focus: true

        Keys.onReturnPressed : {
            textEntered(text)
            text = ""
        }
    }
}
