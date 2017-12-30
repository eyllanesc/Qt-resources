/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Item {
    id: container
    width: 400; height: 400

    Rectangle {
        color : "blue"

        width : 100
        height: 100
        Rectangle {
            id: myRect
            width: 20; height: 20
            y : 50
            x : 20
            color: "red"
        }
        id  : blueRect

    }
    Rectangle {
        x : 200
        width : 100
        height: 100
        color : "yellow"
        id  : yellowRect
    }


    states: State {
        name: "reanchored"
        ParentChange {
            target: myRect
            parent : yellowRect
            x : 60
            y : 20
        }
    }

    transitions: Transition {
        ParentAnimation {
            NumberAnimation {
                properties : "x,y"
                duration: 1000
            }
        }
    }

    MouseArea {
      anchors.fill : parent
      onClicked: container.state = "reanchored"
    }
}
