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
    width: 400; height: 600
    color: "black"

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            x: parent.width/2
            y: parent.height

            emitRate: 500
            lifeSpan: 5000
            lifeSpanVariation: 500
            size: 16

            velocity: AngleDirection { magnitude: 300; angle: -90; angleVariation: 2 }
            acceleration: PointDirection { y: -100; xVariation: 10 }
        }

        CustomParticle {
            vertexShader: "
                          uniform lowp float qt_Opacity;
                          varying highp float age;

                          void main() {
                              qt_TexCoord0 = qt_ParticleTex;

                              age = (qt_Timestamp - qt_ParticleData.x) / qt_ParticleData.y;
                              if (age < 0. || age > 1.) age = 1.0;

                              highp float size = qt_ParticleData.z;
                              highp vec2 pos = qt_ParticlePos
                                             - size / 2. + size * qt_ParticleTex          // adjust size
                                             + qt_ParticleVec.xy * age * qt_ParticleData.y  // apply speed vector
                                             + 0.5 * qt_ParticleVec.zw * pow(age * qt_ParticleData.y, 2.);

                              gl_Position = qt_Matrix * vec4(pos.x, pos.y, 0, 1);
                          }"

            fragmentShader: "
                            varying highp float age;
                            varying highp vec2 qt_TexCoord0;
                            void main() {
                                //*2 because this generates dark colors mostly
                                highp vec2 circlePos = qt_TexCoord0 * 2.0 - vec2(1.0, 1.0);
                                highp float dist = length(circlePos);
                                highp float circleFactor = max(min(1.0 - dist, 1.0), 0.0);

                                highp float fade = mix(1.0, 0.0, age * age);
                                highp float red = mix(0.0, 0.6, age);

                                gl_FragColor = vec4(red, 1.0, 1.0, 0.0) * circleFactor * fade;
                            }"
        }

        Gravity {
            magnitude: 200
        }
    }
}
