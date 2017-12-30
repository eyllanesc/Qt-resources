/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5 as MyQt

MyQt.Rectangle {
    width: 150; height: 50; color: "lightblue"

    MyQt.Text {
        anchors.centerIn: parent
        text: qsTr("Hello Qt!")
        font.pixelSize: 32
    }
}
