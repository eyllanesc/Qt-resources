import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sensors")

    StackView {
        id: pageStack
        initialItem: "qrc:/NavigationPage.qml"
    }
}
