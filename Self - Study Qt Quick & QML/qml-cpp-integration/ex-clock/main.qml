/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import ClockComponents 1.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360; height: 360
    Rectangle {
        anchors.fill: parent
        color: "#000000"

        Ellipse {
            anchors.fill: parent

            anchors.centerIn: parent

            color: "#ffffff"
            style: Ellipse.Filled

            ClockHand {
                type: ClockHand.HourHand
                color: "#0000ff"
                angle: 190

                anchors.fill: parent

                Timer {
                    id: hour
                    interval: IntervalSettings {
                        unit: IntervalSettings.Hours
                        duration: 1
                    }
                }
            }
            ClockHand {
                type: ClockHand.MinuteHand
                color: "#ff0000"
                angle: 60

                anchors.fill: parent

                Timer {
                    id: minute
                    interval: IntervalSettings {
                        unit: IntervalSettings.Minutes
                        duration: 1
                    }
                }
            }
            ClockHand {
                type: ClockHand.SecondHand
                color: "#00ff00"

                anchors.fill: parent

                Timer {
                    id: second
                    interval: IntervalSettings {
                        unit: IntervalSettings.Seconds
                        duration: 1
                    }
                }
            }
        }

        Component.onCompleted: {
            hour.start();
            minute.start();
            second.start();
        }
    }
}
