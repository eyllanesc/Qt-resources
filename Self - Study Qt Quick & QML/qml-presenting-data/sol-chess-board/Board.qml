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
    id: board
    x: 5; y: 5
    rows: 8; columns: 8; spacing: 5
    property alias model: repeater.model
    signal clicked(int square)

    Repeater {
        id: repeater

        model: {
            var board = [true]
            for (var i = 1; i < 64; ++i)
                board[i] = false;
            board;
        }

        Rectangle {
            width: 50; height: 50
            color: {
                var row = Math.floor(index / 8);
                var column = index % 8
                if ((row + column) % 2 == 1)
                    repeater.model[index] ? "#404040" : "black";
                else
                    repeater.model[index] ? "gray" : "white";
            }
            MouseArea {
                anchors.fill: parent
                onClicked: board.clicked(index)
            }
        }
    }
}
