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
    width: 400; height: 100
    color: "lightblue"
    
    TextInput {
        x: parent.width * 0.1; y: parent.height * 0.1
        width: parent.width * 0.75
        font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.4 : parent.height * 0.4 }
        text: qsTr("Qt Quick")
        focus: true
        onTextChanged: color = "green"
        wrapMode: Text.WordWrap
    }
}

