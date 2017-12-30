/*

uniform sampler2D source;
uniform float filterPosition;
uniform float tailLength;
varying highp vec2 qt_TexCoord0;

void main() {
    highp vec4 color = texture2D(source, qt_TexCoord0);
    color.a = (qt_TexCoord0.t - filterPosition + tailLength) / tailLength;
    gl_FragColor = color;
}

*/
