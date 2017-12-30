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
    width: 400; height: 300
    color: "#303030"
    property date today: new Date()
    property int daysInMonth: new Date(today.getYear(), today.getMonth() + 1, 0).getDate()

    Item {
        id: dayLabels
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10

        Grid {
            id: grid
            columns: 7
            rows: 6
            spacing: 10

            Repeater {
                model: daysInMonth

                Rectangle {
                    color: "#eeeeee"
                    width: (root.width - 20 - 60)/7
                    height: Math.min(width, (root.height - 20 - (grid.rows - 1)*10)/grid.rows)

                    Text {
                        anchors.centerIn: parent
                        text: index + 1
                    }
                }
            }
        }
    }
}
