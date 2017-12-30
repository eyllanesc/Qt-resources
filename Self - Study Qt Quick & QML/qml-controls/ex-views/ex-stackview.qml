/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("StackView")

    header: Label {
        horizontalAlignment: Qt.AlignHCenter
        text: qsTr("This is a header")
    }
    footer: TabBar {
        id: tabBar
        TabButton {
            text: qsTr("Change page")
            onClicked: {
                if (stackView.depth === 1)
                    stackView.push("ex-views/Page2.qml");
                else
                    stackView.pop();
            }
        }
    }
    Popup { id: popup
        width: parent.width * 0.5; height: parent.height * 0.5
        x: (parent.width - width) / 2; y: (parent.height - height) / 2
        modal: true
        Text {
            anchors.centerIn: parent
            text: qsTr("Text in popup")
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "ex-views/Page1.qml"
        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
    }
}
