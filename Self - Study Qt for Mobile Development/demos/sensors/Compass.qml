import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import QtSensors 5.0

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
        id: compass
        anchors.centerIn: parent
        width: parent.width / 2
        height: width
        border.color: "white"
        border.width: 5
        radius: width / 2
        color: "black"
        Text {
            text: qsTr("N")
            x: parent.width / 2 - 14
            y: 35
            font.pixelSize: 32
            color: "white"
        }
        Repeater {
            model: 4
            Rectangle {
                width: 10
                height: 30
                rotation: index * 90
                x: {
                    switch (index) {
                    case 0:
                    case 2:
                        parent.width / 2 - width / 2;
                        break;
                    case 1:
                        parent.width - width - 10;
                        break;
                    default:
                        10;
                        break;
                    }
                }
                y: {
                    switch (index) {
                    case 0:
                        5;
                        break;
                    case 1:
                    case 3:
                        parent.height / 2 - width / 2 - 5;
                        break;
                    default:
                        parent.height - height - 5;
                        break;
                    }
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
    Compass {
        active: parent.visible
        onReadingChanged: {
            console.log("Compass " + reading.azimuth);
            compass.rotation = reading.azimuth;
        }
    }
}
