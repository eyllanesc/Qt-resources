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
    width: picture.width; height: picture.height

    ShaderEffectSource {
        id: effectSource
        sourceItem: Image {
            id: picture
            source: "../images/tampere.jpg"
        }
    }

    ShaderEffect {
        id: effect
        anchors.centerIn: parent
        width: picture.width
        height: picture.height

        property variant source: effectSource
        property real filterPosition: 0.0
        property real tailLength: 0.1

        SequentialAnimation on filterPosition {
            loops: Animation.Infinite
            NumberAnimation { to: 1 + effect.tailLength; duration: 2000; easing.type: Easing.InOutSine }
            PauseAnimation { duration: 500 }
            NumberAnimation { to: 0; duration: 2000; easing.type: Easing.InOutSine }
            PauseAnimation { duration: 500 }
        }

        fragmentShader: "
                        uniform sampler2D source;
                        uniform float filterPosition;
                        uniform float tailLength;
                        varying highp vec2 qt_TexCoord0;

                        void main() {
                            highp vec4 color = texture2D(source, qt_TexCoord0);
                            color.a = (qt_TexCoord0.t - filterPosition + tailLength) / tailLength;
                            gl_FragColor = color;
                        }"
    }
}
