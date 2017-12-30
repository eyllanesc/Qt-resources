/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Layouts")
    width: 640
    height: 480
    visible: true

    GridLayout {
        anchors.fill: parent
        columns: 3
        Button {
            text: qsTr("Btn 1")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
        }
        Button {
            text: qsTr("Btn 2")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
            Layout.fillHeight: true
        }
        Button {
            text: qsTr("Btn 3")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
        }
        Button {
            text: qsTr("Btn 4")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
            Layout.fillWidth: true
        }
        Button {
            text: qsTr("Btn 5")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
        }
        Button {
            text: qsTr("Btn 6")
            onClicked: messageDialog.show(qsTr("Btn pressed"))
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
