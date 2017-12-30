/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

FocusScope {
    property alias text: editor.text

    Rectangle {
        id: rectangle
        anchors.fill: parent
        clip: true

        TextInput {
            id: editor
            anchors.centerIn: parent
            focus: true
        }
    }
}
