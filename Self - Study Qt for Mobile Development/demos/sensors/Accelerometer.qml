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

    Image {
        id: ball
        x: parent.width / 2 - width / 2
        y: parent.height / 2 - height / 2
        source: "qrc:/images/ball.png"
    }

    Accelerometer {
        id: accelerometer
        active: parent.visible
        onReadingChanged: {
            var newX = ball.x - Math.floor(accelerometer.reading.x);
            ball.x = (newX < 0) ? 0 : ((newX < parent.width - ball.width) ? newX : (parent.width - ball.width));
            var newY = ball.y + Math.floor(accelerometer.reading.y);
            ball.y = (newY < 0) ? 0 : ((newY < parent.height - ball.height) ? newY : (parent.height - ball.height));
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (accelerometer.active) {
                accelerometer.stop();
                ball.x = parent.width / 2 - ball.width / 2;
                ball.y = parent.height / 2 - ball.height / 2;
            }
            else {
                accelerometer.start();
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
