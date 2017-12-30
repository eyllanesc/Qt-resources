/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Particles 2.0

Image {
    id: picture
    source: "../images/tampere.jpg"
    smooth: true

    // Hint: use "../images/sizeTable.png" as sizeTable: value
    Image {
        source: "../images/snowflake.png"
    }
}
