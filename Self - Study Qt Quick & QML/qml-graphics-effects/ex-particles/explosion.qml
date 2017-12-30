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

Rectangle {
    width: 400; height: 400
    color: "black"

    Timer {
        interval: 2000
        running: true
        repeat: true
        onTriggered: emitter.pulse(50)
    }

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            id: emitter
            anchors.centerIn: parent

            enabled: false
            emitRate: 700
            lifeSpan: 500
            size: 16

            velocity: AngleDirection { magnitude: 500; angleVariation: 360 }
        }

        ImageParticle {
            source: "../images/particle.png"
            sizeTable: "../images/sizeTable.png"
            blueVariation: 100
        }
    }
}
