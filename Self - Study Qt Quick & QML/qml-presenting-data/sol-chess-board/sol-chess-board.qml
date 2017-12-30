/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

// Board and Knight are implicitly imported from Board.qml and Knight.qml.

Rectangle {
    width: 445; height: 445; color: "brown"

    Board {
        id: board
        onClicked: knight.moveTo(board, square)
    }

    Knight {
        id: knight
    }
}
