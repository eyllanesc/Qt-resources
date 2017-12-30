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
    id: root
    width: 300; height: 400
    
    property string currentScreen: "appointments"

    AppointmentsScreen {
        id: appointmentsScreen
    }

    JournalScreen {
        id: journalScreen
    }

    focus: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: if (appointmentsScreen.y == 0) {
                       currentScreen = "journal";
                   } else if (journalScreen.y == 0) {
                       currentScreen = "appointments";
                   }
    }

    states: [
        State {
            name: "appointments"
            when: currentScreen == "appointments"
            PropertyChanges { target: appointmentsScreen; y: 0; z: 1 }
            PropertyChanges { target: journalScreen; y: root.height; z: 0 }
        },
        State {
            name: "journal"
            when: currentScreen == "journal"
            PropertyChanges { target: appointmentsScreen; y: root.height; z: 0 }
            PropertyChanges { target: journalScreen; y: 0; z: 1 }
        }
    ]

    transitions: [
        Transition {
            from: "appointments"; to: "journal"
            PropertyAnimation {
                target: journalScreen
                property: "y"
                duration: 500
            }
        },
        Transition {
            from: "journal"; to: "appointments"
            PropertyAnimation {
                target: appointmentsScreen
                property: "y"
                duration: 500
            }
        }
    ]
}
