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

Item{
    id: container
    property variant progress: 0

    Rectangle {
        anchors.fill: parent; smooth: true
        border.color: "white"; border.width: 0; radius: height/2 - 2
        gradient: Gradient {
            GradientStop { position: 0; color: "#66343434" }
            GradientStop { position: 1.0; color: "#66000000" }
        }
    }

    ParticleSystem{
        running: container.visible
        id: barSys
    }
    ImageParticle{
        color: "lightsteelblue"
        alpha: 0.1
        colorVariation: 0.05
        source: "images/particle.png"
        system: barSys
    }
    Emitter{
        y: 2; height: parent.height-4;
        x: 2; width: Math.max(parent.width * progress - 4, 0);
        velocity: AngleDirection{ angleVariation: 180; magnitudeVariation: 12 }
        system: barSys
        emitRate: width;
        lifeSpan: 1000
        size: 20
        sizeVariation: 4
        endSize: 12
        maximumEmitted: parent.width;
    }

    Text {
        text: Math.round(progress * 100) + "%"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: Qt.rgba(1.0, 1.0 - progress, 1.0 - progress,0.9); font.bold: true; font.pixelSize: 15
    }
}
