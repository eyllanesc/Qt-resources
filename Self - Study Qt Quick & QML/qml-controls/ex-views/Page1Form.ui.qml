import QtQuick 2.4
import QtQuick.Controls 2.1

Item {
    id: item1
    property alias button: button

    Button {
        id: button
        y: 327
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
        x: 94
        y: 149
        text: qsTr("Page 1")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 23
    }
}
