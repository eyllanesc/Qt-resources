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
    width: 400; height: 400
    color: "black"
    id: root

    ListModel {
        id: nameModel
        ListElement { xcolor: "white" }
        ListElement { xcolor: "red" }
        ListElement { xcolor: "green" }
        ListElement { xcolor: "blue" }
    }

    Component {
        id: nameDelegate
        Text {
            color: xcolor
            width: 20
            height: 20
            text: index
            x: 200 + (Math.cos((index * 0.25 * 2 * Math.PI + root.value)) * 100.0)
            y: 200 + (Math.sin((index * 0.25 * 2 * Math.PI + root.value)) * 100.0)
        }
    }

    Item {
        anchors.fill: parent
        Repeater {
            model: nameModel
            delegate: nameDelegate
        }
    }

    property real value: 0
    NumberAnimation on value {
        from: 0.0; to: 2.0 * Math.PI
        duration: 1000
        running: true
    }
}
