/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.7
import QtQuick.Window 2.0

Window {
    width: 360
    height: 360
    visible: true

    Component {
        id: cityDelegate

        Column {
            height: childrenRect.height
            width: parent.width

            Text {
                id: cityText
                text: city + " (" + country + ")"
                width: parent.width
                wrapMode: Text.WordWrap
            }

            Text {
                text: "Population: " + population + ", area: " + area
                width: parent.width
                wrapMode: Text.WordWrap
            }
        }
    }

    ListView {
        model: _model
        delegate: cityDelegate

        anchors.fill: parent
        section.property: qsTr("country")
        section.delegate: Rectangle {
            height: 20
            width: parent.width
            color: "red"

            Text {
                text: section
            }
        }
    }
}
