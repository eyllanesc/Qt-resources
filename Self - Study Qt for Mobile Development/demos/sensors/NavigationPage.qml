import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Rectangle {
    width: 400
    height: 62

    property int topMargin: 10

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

    Text {
        id: textItem
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Sensors")
        color: "white"
        font.pixelSize: Math.floor(0.09 * parent.width)
    }

    Flickable {
        anchors.top: textItem.bottom
        anchors.topMargin: topMargin
        anchors.bottom: parent.bottom
        width: parent.width
        flickableDirection: Flickable.VerticalFlick
        clip: true
        contentHeight: button1.height * 6

        ColumnLayout {
            anchors.fill: parent

            Button {
                id: button1
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/Accelerometer.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Accelerometer")
                }
            }

            Button {
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/AmbientLight.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Ambient Light")
                }
            }

            Button {
                visible: Qt.platform.os !== "android"
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/Compass.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Compass")
                }
            }

            Button {
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/Gyroscope.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Gyroscope")
                }
            }

            Button {
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/Rotation.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Rotation Sensor")
                }
            }

            Button {
                width: parent.width
                onClicked: {
                    pageStack.push({item: "qrc:/Tilt.qml"});
                }
                style: PushButtonStyle {
                    buttonText: qsTr("Tilt Sensor")
                }
            }
        }
    }
}
