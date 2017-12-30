import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import QtSensors 5.0
import QtQuick.Window 2.1

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

    Rectangle {
        anchors.centerIn: parent
        width: parent.width * 0.5
        height: parent.height * 0.1
        radius: 5
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#eaf10c";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
        Rectangle {
            id: bubbleParent
            anchors.centerIn: parent
            width: parent.width * 0.2
            height: parent.height * 0.7
            radius: 5
            color: "black"
            clip: true

            Rectangle {
                id: bubble
                width: parent.width / 2
                height: parent.height / 4
                radius: 5
                x: parent.width / 2 - width / 2
                y: parent.height / 2 - height / 2
                gradient: Gradient {
                    GradientStop {
                        position: 0.00;
                        color: "#276be0";
                    }
                    GradientStop {
                        position: 1.00;
                        color: "#ffffff";
                    }
                }
            }
        }
    }

    TiltSensor {
        id: tiltSensor
        active: parent.visible
        onReadingChanged: {
            var rotation = reading.xRotation;
            if (rotation > 0) {
                if (bubble.x < bubbleParent.width) {
                    bubble.x++;
                }
            }
            else if (rotation < 0) {
                if (bubble.x > -bubble.width) {
                    bubble.x--;
                }
            }
            else {
                if (bubble.x < (bubbleParent.width / 2 - bubble.width / 2)) {
                    bubble.x++;
                }
                else if (bubble.x > (bubbleParent.width / 2 - bubble.width / 2)) {
                    bubble.x--;
                }
            }
        }
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
}
