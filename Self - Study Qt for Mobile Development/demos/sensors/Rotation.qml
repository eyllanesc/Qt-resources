import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import QtSensors 5.0
import QtQuick.Particles 2.0

Rectangle {
    property int bottomMargin: 10
    property int columnSpacing: 50

    id: root
    width: 460
    height: 640

    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#000000";
        }
        GradientStop {
            position: 1.00;
            color: "#b9b3b3";
        }
    }

    focus: true
    Keys.onBackPressed: {
        pageStack.pop();
    }


    ToolBar {
        id: bottomToolbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: bottomMargin
        width: parent.width

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: columnSpacing
            ToolButton {
                iconSource: "qrc:/images/arrow_left.png"
                onClicked: {
                    pageStack.pop();
                }
            }
        }
        style: ToolBarStyle {
            background: Item {
            }
        }
    }

    RotationSensor {
        id: rotationSensor
        active: root.visible
    }

    ParticleSystem {
        running: root.visible

        Emitter {
            x: 0.1 * root.width
            y: 0.1 * root.height
            emitRate: 10 * Math.abs(rotationSensor.reading.x)
            lifeSpan: 3200
            lifeSpanVariation: 500
            velocity: AngleDirection {
                angle: 0
                angleVariation: 5
                magnitude: 90
                magnitudeVariation: 50
            }
        }

        ImageParticle {
            source: "qrc:/images/face-smile.png"
            redVariation: 1.0
            blueVariation: 1.0
            greenVariation: 1.0

        }
        Gravity {
            magnitude: 200
        }
    }
}
