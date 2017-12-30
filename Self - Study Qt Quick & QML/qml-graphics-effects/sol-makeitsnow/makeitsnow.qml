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

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            id: emitter
            y: 0
            width: parent.width

            emitRate: 4
            lifeSpan: 15000
            lifeSpanVariation: 500
            velocity: PointDirection { y: 20; yVariation: 10; xVariation: 10 }
            size: 64
        }

        Affector {
            anchors.fill: parent

            onAffectParticles: {
                for (var i=0; i<particles.length; i++) {
                    var particle = particles[i];
                    if (particle.r == 0.0) {
                        particle.r = Math.random() - 0.5;
                    }
                    particle.rotation += particle.r * dt;
                    particle.update = 1;
                }
            }
        }

        ImageParticle {
            source: "../images/snowflake.png"
            sizeTable: "../images/sizeTable.png"
            redVariation: 20
        }
    }
}
