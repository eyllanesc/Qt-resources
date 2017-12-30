/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Window {
    width: 640
    height: 480
    title: qsTr("Delegate Model")
    color: "white"
    visible: true

    property int level: 0

    ListView {
        anchors.fill: parent

        model: DelegateModel {
            model: delegateModel

            delegate: Item {
                property var view: ListView.view
                width: childrenRect.width
                height: childrenRect.height
                Row {
                    spacing: 10
                    Text { text: nodeName }
                    Text { text: qsTr("Example Column") }
                }
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.RightButton | Qt.LeftButton
                    onClicked: {
                        if (mouse.button === Qt.LeftButton) {
                            if (model.hasModelChildren) {
                                ++level;
                                view.model.rootIndex = view.model.modelIndex(index);
                            }
                        }
                        else if (mouse.button === Qt.RightButton) {
                            if (level > 0) {
                                --level;
                                view.model.rootIndex = view.model.parentModelIndex(index);
                            }
                        }
                    }
                }
            }
        }
    }
}
