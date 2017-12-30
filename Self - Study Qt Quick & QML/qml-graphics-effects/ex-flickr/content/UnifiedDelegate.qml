/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Particles 2.0

Package {
    function photoClicked() {
        imageDetails.photoTitle = title;
        imageDetails.photoTags = tags;
        imageDetails.photoWidth = photoWidth;
        imageDetails.photoHeight = photoHeight;
        imageDetails.photoType = photoType;
        imageDetails.photoAuthor = photoAuthor;
        imageDetails.photoDate = photoDate;
        imageDetails.photoUrl = url;
        imageDetails.rating = 0;
        scaleMe.state = "Details";
    }

    Item {
        id: gridwrapper;
        width: GridView.view.cellWidth; height: GridView.view.cellHeight
        Package.name: "grid"
    }
    Item {
        id: streamwrapper;
        width: 80; height: 80
        Package.name: "stream"
    }
    Item {
        //anchors.centerIn: parent//Doesn't animate :(
        width: 80; height: 80
        scale: 0.0
        Behavior on scale { NumberAnimation { easing.type: Easing.InOutQuad} }
        id: scaleMe

        Item {
            id: whiteRectContainer
            width: 77; height: 77; anchors.centerIn: parent
            Rectangle {
                id: whiteRect; width: 77; height: 77; color: "#dddddd"; smooth: true
                x:0; y:0
                Image { id: thumb; source: imagePath; x: 1; y: 1; smooth: true }
                Image { source: "images/gloss.png" }
                MouseArea { anchors.fill: parent; onClicked: photoClicked() }
            }
        }

        Connections {
            target: toolBar
            onButton2Clicked: if (scaleMe.state == 'Details' ) scaleMe.state = 'Show'
        }

            state: 'inStream'
        states: [
            State {
                name: "Show"; when: thumb.status == Image.Ready
                PropertyChanges { target: scaleMe; scale: 1; }
            },
            State {
                name: "Details"
                PropertyChanges { target: scaleMe; scale: 1 }
                ParentChange { target: whiteRect; x: 10; y: 20; parent: imageDetails.frontContainer }
                PropertyChanges { target: background; state: "DetailedView" }
            }
        ]
        transitions: [
            Transition {
                from: "Show"; to: "Details"
                ParentAnimation {
                    via: foreground
                    NumberAnimation { properties: "x,y"; duration: 500; easing.type: Easing.InOutQuad }
                }
            },
            Transition {
                from: "Details"; to: "Show"
                SequentialAnimation{
                    ParentAnimation {
                        via: foreground
                        NumberAnimation { properties: "x,y"; duration: 500; easing.type: Easing.InOutQuad }
                    }
                }
            }
        ]
        Item{
            id: stateContainer
            states: [
                State {
                    name: 'inStream'
                    when: screen.inGridView == false
                    ParentChange { 
                        target: scaleMe; parent: streamwrapper 
                        x: 0; y: 0; 
                    }
                },
                State {
                    name: 'inGrid'
                    when: screen.inGridView == true
                    ParentChange {
                        target: scaleMe; parent: gridwrapper
                        x: 0; y: 0;
                    }
                }
            ]

            transitions: [
                Transition {
                    ParentAnimation {
                        NumberAnimation { target: scaleMe; properties: 'x,y,width,height'; duration: 300 }
                    }
                }
            ]
        }
    }
}
