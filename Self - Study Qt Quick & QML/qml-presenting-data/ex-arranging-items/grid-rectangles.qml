/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Grid {
    x: 15; y: 15; width: 300; height: 300

    columns: 2; rows: 2; spacing: 20

    Rectangle { width: parent.width * 0.42; height: parent.height * 0.42; color: "red" }
    Rectangle { width: parent.width * 0.42; height: parent.height * 0.42; color: "green" }
    Rectangle { width: parent.width * 0.42; height: parent.height * 0.42; color: "silver" }
    Rectangle { width: parent.width * 0.42; height: parent.height * 0.42; color: "blue" }
}
