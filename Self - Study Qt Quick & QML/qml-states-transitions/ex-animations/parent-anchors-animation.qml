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

        width : parent.width * 0.25
        height: width
        Rectangle {
            id: myRect
            width: parent.width * 0.2; height: parent.width * 0.2
            y : parent.width * 0.5
            x : parent.height * 0.2
            color: "red"
        }
        id  : blueRect

    }
    Rectangle {
        x : parent.width / 2
        width : parent.width * 0.25
        height: width
        color : "yellow"
        id  : yellowRect
    }


    states: State {
        name: "reanchored"
        ParentChange {
            target: myRect;
            parent : yellowRect
            y : parent.width * 0.4
            x : parent.height * 0.2
        }
        AnchorChanges {
            target : myRect
            anchors.left : parent.left
            anchors.right : parent.right
        }

    }

    transitions: Transition {
        // smoothly reanchor myRect and move into new position
        ParentAnimation {
            NumberAnimation {
                properties : "x,y"
                duration: 1000
            }
        }
        AnchorAnimation {
            duration : 1000
        }

    }

    MouseArea {
      anchors.fill : parent
      onClicked: container.state = "reanchored"
    }
}
