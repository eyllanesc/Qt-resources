import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import QtSensors 5.0
import QtGraphicalEffects 1.0

Rectangle {
    property int bottomMargin: 10
    property int columnSpacing: 50

    Component.onDestruction: {
        console.log("what")
    }

    id: root
    width: 460
    height: 640
    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#2d69cf";
        }
        GradientStop {
            position: 1.00;
            color: "#ffffff";
        }
    }

    Rectangle {
        id: ground
        width: parent.width * 3
        x: -parent.width / 2
        y: 0.6 * parent.height
        height: parent.height
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#63d74c";
            }
            GradientStop {
                position: 1.00;
                color: "#1f4901";
            }
        }
        Behavior on rotation {
            NumberAnimation {

            }
        }
    }

    Rectangle {
        id: sun
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.top: parent.top
        anchors.topMargin: 80
        width: 60
        height: 60
        radius: width / 2
        clip: true
        RadialGradient {
            anchors.fill: parent
            source: sun
            horizontalOffset: -20
            verticalOffset: -15
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: "#ffffff";
                }
                GradientStop {
                    position: 1.00;
                    color: "#ffff00";
                }
            }
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
    Gyroscope {
        active: parent.visible
        onReadingChanged: {
            if (reading.z > 0 && ground.rotation < 30)
                ground.rotation++;
            else if (reading.z < 0 && ground.rotation > -30)
                ground.rotation--;
        }
    }
}
