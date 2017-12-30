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

    color: "black"

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

    AmbientLightSensor {
        active: parent.visible
        onReadingChanged: {
            switch (reading.lightLevel) {
            case AmbientLightReading.Dark:
                root.color = "#f0f0f0";
                break;
            case AmbientLightReading.Twilight:
                root.color = "#b0b0b0";
                break;
            case AmbientLightReading.Light:
                root.color = "#808080";
                break;
            case AmbientLightReading.Bright:
                root.color = "#404040";
                break;
            case AmbientLightReading.Sunny:
                root.color = "#000000";
                break;
            default:
                root.color = "#000000";
                break;
            }
        }
    }
}
