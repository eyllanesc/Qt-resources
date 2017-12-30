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
    width: 400; height: 400; color: "black"

    Grid {
        id: grid
        x: 5; y: 5
        rows: 5; columns: 5; spacing: 10

        Repeater { model: 24
                   Rectangle { width: root.width / grid.columns - grid.spacing; height: root.height / grid.rows - grid.spacing
                               color: "lightgreen"

                               Text { text: index
                                      font.pointSize: 30
                                      anchors.centerIn: parent } }
        }
    }
}
