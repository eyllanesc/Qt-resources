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
    width: 600; height: 600

    ShaderEffectSource {
        id: effectSource
        sourceItem: Image {
            id: butterfly
            source: "../images/butterfly.png"
            smooth: true
        }
    }

    ShaderEffect {
        anchors.centerIn: parent
        width: butterfly.width
        height: butterfly.height

        property variant source: effectSource
        property real filterPosition: 0.0

        SequentialAnimation on filterPosition {
            loops: Animation.Infinite
            NumberAnimation { to: 1; duration: 500; easing.type: Easing.InOutSine }
            PauseAnimation { duration: 500 }
            NumberAnimation { to: 0; duration: 500; easing.type: Easing.InOutSine }
            PauseAnimation { duration: 500 }
        }

        fragmentShader: "
                        uniform sampler2D source;
                        uniform float filterPosition;
                        varying highp vec2 qt_TexCoord0;

                        void main() {
                            highp vec4 color = texture2D(source, qt_TexCoord0);
                            if (qt_TexCoord0.s < filterPosition) {
                                float grey = color.r * 0.299 + color.g * 0.587 + color.b * 0.114;
                                gl_FragColor = vec4( grey, grey, grey, color.a );
                            } else {
                                gl_FragColor = color;
                            }
                        }"
    }
}
