/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Component {
   Item {
      width: parent.width; height: 100

      Rectangle {
         width: Math.max(childrenRect.width + 16, parent.width)
         height: parent.height; // clip: true
         color: "#505060"; border.color: "#8080b0"; radius: 8

         Column { Text { x: 6; color: "white"
                         font.pixelSize: 32; text: title }
                  Text { x: 6; color: "white"
                         font.pixelSize: 16; text: link } }
      }
   }
}
