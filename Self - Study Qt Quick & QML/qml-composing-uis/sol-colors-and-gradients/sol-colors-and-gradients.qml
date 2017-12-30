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
    width: 400; height: 150
    color: "gray"

    Rectangle {
        x: 25; y: 25
        width: 100; height: 100

        gradient: Gradient {
            GradientStop {
                position: 0.0; color: "white"
            }
            GradientStop {
                position: 1.0; color: "blue"
            }
        }
    }

    Rectangle {
        x: 150; y: 25
        width: 100; height: 100
        rotation: 90

        gradient: Gradient {
            GradientStop {
                position: 0.0; color: "white"
            }
            GradientStop {
                position: 1.0; color: "darkred"
            }
        }
    }

    Rectangle {
        x: 275; y: 25
        width: 100; height: 100
        color: "black"
        clip: true

        Rectangle {
            x: -21; y: -21
            width: 142; height: 142
            rotation: 45

            gradient: Gradient {
                GradientStop {
                    position: 0.0; color: "white"
                }
                GradientStop {
                    position: 1.0; color: "darkgreen"
                }
            }
        }
    }
}
