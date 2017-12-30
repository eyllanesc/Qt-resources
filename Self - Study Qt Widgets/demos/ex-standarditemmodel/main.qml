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
    width: 300
    height: 300
    visible: true

    ListView {
        model: model_

        delegate: Text { text: display }

        anchors.fill: parent
    }
}
