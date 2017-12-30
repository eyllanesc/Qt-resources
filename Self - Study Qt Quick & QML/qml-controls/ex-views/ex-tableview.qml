/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    title: qsTr("Table View")
    width: 400
    height: 400
    visible: true

    Component.onCompleted: {
        for (var i = 0; i < 10000; ++i) {
            simpleModel.append({"name": "Item " + i, "btnChecked": "false"});
        }
    }

    TableView {
        anchors.fill: parent
        TableViewColumn {
            title: qsTr("Item")
            role: "name"
        }
        TableViewColumn {
            title: qsTr("Button")
            role: "btnChecked"
            delegate: tableViewDelegate
        }
        model: simpleModel
    }

    Component {
        id: tableViewDelegate
        Item {
            RadioButton {
                checked: (styleData.value === "false") ? false : true
                onClicked: {
                    checked ? simpleModel.setProperty(styleData.row, "btnChecked", "true") : simpleModel.setProperty(styleData.row, "btnChecked", "false");
                }
                // State saved into the model
                onVisibleChanged: {
                    checked = (styleData.value === "false") ? false : true;
                }
            }
        }
    }

    ListModel {
        id: simpleModel
    }
}


