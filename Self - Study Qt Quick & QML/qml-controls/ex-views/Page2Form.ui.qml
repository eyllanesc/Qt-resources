import QtQuick 2.4
import QtQuick.Controls 2.1

Item {
    id: item1
    property alias button: button

    Button {
        id: button
        y: 302
        text: qsTr("Press me")
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        font.pointSize: 20
    }

    Label {
        id: pageLabel
        x: 155
        y: 89
        text: qsTr("Page 2")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 20
    }
}
