import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 600; height: 600

    ShaderEffectSource {
        id: effectSource
        sourceItem: Rectangle {
            id: flag
            color: "lightBlue"
            border.color: "black"
            border.width: 4
            width: butterfly.width
            height: butterfly.height

            Image {
                id: butterfly
                source: "qrc:/images/butterfly.png"
                smooth: true
            }
        }
    }

    ShaderEffect {
        anchors.centerIn: parent
        width: flag.width
        height: flag.height

        property variant source: effectSource
        property real pi: Math.PI
        property real offset: 0
        NumberAnimation on offset { loops: Animation.Infinite; from: 0; to: Math.PI * 2; duration: 2000 }

        mesh: GridMesh { resolution: Qt.size(100, 1) }

        vertexShader: "
                          uniform highp float height;
                          uniform highp float width;
                          uniform highp float pi;
                          uniform highp float offset;

                          uniform highp mat4 qt_Matrix;
                          attribute highp vec4 qt_Vertex;
                          attribute highp vec2 qt_MultiTexCoord0;
                          varying highp vec2 qt_TexCoord0;

                          void main() {
                              qt_TexCoord0 = qt_MultiTexCoord0;

                              highp vec4 pos = qt_Vertex;
                              highp float angle = 2.0 * pi * pos.x / width;
                              pos.y = pos.y + sin(offset + angle) * height / 20.0;

                              gl_Position = qt_Matrix * pos;
                          }"
    }
}
