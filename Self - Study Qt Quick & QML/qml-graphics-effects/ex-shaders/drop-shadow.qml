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

    ShaderEffectSource {
        id: blurredSource
        smooth: true
        sourceItem: ShaderEffect {
            width: butterfly.width
            height: butterfly.height

            property variant source: effectSource
            property variant delta: Qt.size(1.0 / width, 1.0 / height)

            fragmentShader: "
                            uniform lowp float qt_Opacity;
                            uniform sampler2D source;
                            uniform highp vec2 delta;
                            varying highp vec2 qt_TexCoord0;
                            void main() {
                                gl_FragColor =(0.0538 * texture2D(source, qt_TexCoord0 - 3.182 * delta)
                                             + 0.3229 * texture2D(source, qt_TexCoord0 - 1.364 * delta)
                                             + 0.2466 * texture2D(source, qt_TexCoord0)
                                             + 0.3229 * texture2D(source, qt_TexCoord0 + 1.364 * delta)
                                             + 0.0538 * texture2D(source, qt_TexCoord0 + 3.182 * delta)) * qt_Opacity;
                            }"
        }
    }

    ShaderEffectSource {
        id: darkenedSource
        smooth: true
        sourceItem: ShaderEffect {
            width: butterfly.width
            height: butterfly.height

            property variant source: blurredSource
            property real darkness: 0.3

            fragmentShader: "
                            uniform lowp float qt_Opacity;
                            uniform sampler2D source;
                            uniform highp float darkness;
                            varying highp vec2 qt_TexCoord0;
                            void main() {
                                lowp vec4 color = texture2D(source, qt_TexCoord0);
                                gl_FragColor = vec4(0., 0., 0., darkness * color.a);
                            }"
        }
    }

    ShaderEffect {
        anchors.centerIn: parent
        width: butterfly.width
        height: butterfly.height

        property variant source: effectSource
        property variant shadow: darkenedSource

        property real angle: 0
        property variant offset: Qt.point(15.0 * Math.cos(angle), 15.0 * Math.sin(angle))
        property variant delta: Qt.size(offset.x / width, offset.y / height)

        NumberAnimation on angle { loops: Animation.Infinite; from: 0; to: Math.PI * 2; duration: 6000 }

        fragmentShader: "
                        uniform lowp float qt_Opacity;
                        uniform sampler2D source;
                        uniform sampler2D shadow;
                        uniform highp vec2 offset;
                        uniform highp vec2 delta;
                        varying highp vec2 qt_TexCoord0;
                        void main() {
                            lowp vec4 fg = texture2D(source, qt_TexCoord0);
                            lowp vec4 bg = texture2D(shadow, qt_TexCoord0 + delta);
                            gl_FragColor = (fg + bg * (1. - fg.a)) * qt_Opacity;
                        }"
    }
}
