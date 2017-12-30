/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Image {
    id: knight
    property int cx
    property int cy

    source: "../images/knight.png"

    x: 5 + 55 * cx
    y: 5 + 55 * cy

    function moveTo(board, square) {
        var x = square % 8;
        var y = Math.floor(square/8);
        if ((Math.abs(x - knight.cx) == 1 && Math.abs(y - knight.cy) == 2) ||
            (Math.abs(x - knight.cx) == 2 && Math.abs(y - knight.cy) == 1)) {

            if (!board.model[y * 8 + x]) {
                knight.cx = x;
                knight.cy = y;
                var squares = board.model
                squares[knight.cy * 8 + knight.cx] = true;
                board.model = squares;
            }
        }
    }
}
