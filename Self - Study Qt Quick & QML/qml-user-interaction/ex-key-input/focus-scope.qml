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
    id: root
    width: 300; height: 300
    color: "black"

    Grid {
        anchors.centerIn: parent
        columns: 2
        rows: 2
        spacing: 5
        Editor {
            width: root.width / parent.columns - parent.columnSpacing; height: root.height / parent.rows - parent.rowSpacing
            text: qsTr("Editor 1")
            Component.onCompleted: {
                console.log("Editor 1 created");
            }
        }
        Editor {
            width: root.width / parent.columns - parent.columnSpacing; height: root.height / parent.rows - parent.rowSpacing
            text: qsTr("Editor 2")

            Component.onCompleted: {
                console.log("Editor 2 created");
            }
        }
        Editor {
            width: root.width / parent.columns - parent.columnSpacing; height: root.height / parent.rows - parent.rowSpacing
            text: qsTr("Editor 3")
            focus: true
            Component.onCompleted: {
                console.log("Editor 3 created");
            }
        }
        Editor {
            width: root.width / parent.columns - parent.columnSpacing; height: root.height / parent.rows - parent.rowSpacing
            text: qsTr("Editor 4")
            Component.onCompleted: {
                console.log("Editor 4 created");
            }
        }
    }
}
