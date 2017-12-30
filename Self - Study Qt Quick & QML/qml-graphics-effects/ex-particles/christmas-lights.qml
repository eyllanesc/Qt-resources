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
        onTriggered: emitter.burst(20)
    }

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            id: emitter
            anchors.fill: parent

            enabled: false
            lifeSpan: 1000
            size: 32
        }

        ImageParticle {
            source: "../images/particle.png"
            sizeTable: "../images/sizeTable.png"
            redVariation: 100
            greenVariation: 100
            blueVariation: 100
        }
    }
}
