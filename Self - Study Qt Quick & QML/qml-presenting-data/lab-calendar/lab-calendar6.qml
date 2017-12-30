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
    id: calendar
    width: 400; height: 300
    color: "#303030"
    property date today: new Date()
    property date showDate: new Date()
    property int daysInMonth: new Date(showDate.getFullYear(), showDate.getMonth() + 1, 0).getDate()
    property int firstDay: new Date(showDate.getFullYear(), showDate.getMonth(), 1).getDay()

    Item {
        id: title
        anchors.top: parent.top
        anchors.topMargin: 10
        width: parent.width
        height: childrenRect.height

        Image {
            source: "../images/left.png"
            anchors.left: parent.left
            anchors.leftMargin: 10

            MouseArea {
                anchors.fill: parent
                onClicked: showDate = new Date(showDate.getFullYear(), showDate.getMonth(), 0)
            }
        }

        Text {
            color: "white"
            text: Qt.formatDateTime(showDate, "MMMM yyyy")
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Image {
            source: "../images/right.png"
            anchors.right: parent.right
            anchors.rightMargin: 10

            MouseArea {
                anchors.fill: parent
                onClicked: showDate = new Date(showDate.getFullYear(), showDate.getMonth() + 1, 1)
            }
        }
    }

    function isToday(index) {
        if (today.getFullYear() != showDate.getFullYear())
            return false;
        if (today.getMonth() != showDate.getMonth())
            return false;

        return (index == today.getDate() - 1)
    }

    Item {
        id: dateLabels
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10

        height: calendar.height - title.height - 20 - title.anchors.topMargin
        property int rows: 6

        Item {
            id: dateGrid
            width: parent.width
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom

            Grid {
                columns: 7
                rows: dateLabels.rows
                spacing: 10

                Repeater {
                    model: firstDay + daysInMonth

                    Rectangle {
                        color: {
                            if (index < firstDay)
                                calendar.color;
                            else
                                isToday(index - firstDay) ? "#ffffdd" : "#eeeeee";
                        }
                        width: (calendar.width - 20 - 60)/7
                        height: (dateGrid.height - (dateLabels.rows - 1)*10)/dateLabels.rows

                        Text {
                            anchors.centerIn: parent
                            text: index + 1 - firstDay
                            opacity: (index < firstDay) ? 0 : 1
                            font.bold: isToday(index - firstDay)
                        }
                    }
                }
            }
        }
    }
}
