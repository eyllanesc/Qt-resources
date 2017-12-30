import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property var stackView

    Column {
        anchors.right: parent.right
        Button {
            text: "+"
            onClicked: background.setScale(0.1);
        }
        Button {
            text: "-"
            onClicked: background.setScale(-0.1);
        }
        Button {
            text: qsTr("Back")
            onClicked: stackView.pop();
        }
    }
}
