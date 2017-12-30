/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

 Item {
     width: 1024; height: 600

     Text {
         id: text
         text: "Let your fingers do the walking"
         font.pointSize: 20
         anchors.centerIn: parent
     }

     MultiPointTouchArea {
         anchors.fill: parent
         touchPoints: [
             TouchPoint { id: point1 },
             TouchPoint { id: point2 },
             TouchPoint { id: point3 }
         ]
         onTouchUpdated: {
             var str = "Count: " + touchPoints.length + "\n"
             for( var i=0; i < touchPoints.length; i++) {
                 str = str + touchPoints[i].pointId + ": (" + touchPoints[i].x + " , " + touchPoints[i].y + ")\n"
             }
             text.text = str
         }
     }


     Box {
         color: "green"
         point: point1
     }

     Box {
         color: "blue"
         point: point2
     }

     Box {
         color: "yellow"
         point: point3
     }
 }
