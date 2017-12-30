import QtQuick 2.4

Rectangle {
    id: rootItem
    width: 50
    height: width
    radius: width / 2

    color: Qt.rgba(0, 0.8, 0)

    border { width: 6; color: Qt.rgba(0.8, 0, 0, 0.6) }

    SequentialAnimation on opacity {
        running: rootItem.visible
        PropertyAnimation {
            from: 0.2
            to: 0.8
            duration: 200
        }
        PropertyAnimation {
            from: 0.8
            to: 0.2
            duration: 200
        }
        onRunningChanged: {
            if (!running)
                rootItem.visible = false;
        }
    }
}
