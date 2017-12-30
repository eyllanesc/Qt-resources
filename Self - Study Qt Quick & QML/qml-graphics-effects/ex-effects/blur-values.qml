/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtGraphicalEffects 1.0

Item {
    width: 1250
    height: 200

    Row {
        anchors.fill: parent
        spacing: 20
        Rectangle {
            width: parent.width * 0.33 - parent.spacing; height: parent.height
            color: "lightblue"
            Text {
                id: textElement1
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Qt Quick"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
                visible: false
            }
            FastBlur {
                anchors.fill: textElement1
                source: textElement1
                radius: 1.0
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                text: qsTr("blurRadius: 1"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
                color: "darkBlue"
            }
        }

        Rectangle {
            width: parent.width * 0.33 - parent.spacing; height: parent.height
            color: "lightblue"
            Text {
                id: textElement2
                visible: false
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Qt Quick"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
            }
            FastBlur {
                anchors.fill: textElement2
                source: textElement2
                radius: 3.0
            }
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                text: qsTr("blurRadius: 3"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
                color: "darkBlue"
            }
        }

        Rectangle {
            width: parent.width * 0.33 - parent.spacing; height: parent.height
            color: "lightblue"
            Text {
                id: textElement3
                visible: false
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Qt Quick"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.2 : parent.height * 0.2 }
            }
            FastBlur {
                anchors.fill: textElement3
                source: textElement3
                radius: 5.0
            }
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                text: qsTr("blurRadius: 5"); font { family: "Helvetica"; pixelSize: (parent.height > parent.width) ? parent.width * 0.1 : parent.height * 0.1 }
                color: "darkBlue"
            }
        }
    }
}
