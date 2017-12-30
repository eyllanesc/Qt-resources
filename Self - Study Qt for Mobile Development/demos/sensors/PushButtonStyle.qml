import QtQuick 2.1
import QtQuick.Controls.Styles 1.1

ButtonStyle {
    property string buttonText
    property int rightMargin: 10

    background: Rectangle {
        implicitWidth: parent.width
        color: "black"
        radius: 0.02 * width
        opacity: 0.2
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#ccc7c7";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
        Image {
            anchors.right: parent.right
            anchors.rightMargin: rightMargin
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/arrow_right.png"
        }
    }
    label: Text {
        text: buttonText
        font.pixelSize: Math.floor(0.05 * parent.width)
        color: "white"
    }
}


