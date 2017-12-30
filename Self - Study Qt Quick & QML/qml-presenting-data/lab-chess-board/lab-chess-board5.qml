/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Rectangle {
    width: 445; height: 445; color: "brown"

    Grid {
        x: 5; y: 5
        rows: 8; columns: 8; spacing: 5

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
                    onClicked: {
                        var x = index % 8;
                        var y = Math.floor(index/8);
                        if ((Math.abs(x - knight.cx) == 1 && Math.abs(y - knight.cy) == 2) ||
                            (Math.abs(x - knight.cx) == 2 && Math.abs(y - knight.cy) == 1)) {

                            if (!repeater.model[y * 8 + x]) {
                                knight.cx = x;
                                knight.cy = y;
                                var squares = repeater.model
                                squares[knight.cy * 8 + knight.cx] = true;
                                repeater.model = squares;
                            }
                        }
                    }
                }
            }
        }
    }

    Image {
        id: knight
        property int cx
        property int cy

        source: "../images/knight.png"

        x: 5 + 55 * cx
        y: 5 + 55 * cy
    }
}
