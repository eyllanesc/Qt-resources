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
    width: 100
    height: 62

    property alias text: editor.text

    TextInput {
        id: editor
        anchors.centerIn: parent
        focus: true
    }
}
