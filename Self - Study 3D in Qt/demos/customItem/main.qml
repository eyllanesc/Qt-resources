import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.4
import DemoItems 1.0

Item {
    id: root
    function showTouchIndicator(position) {
        touchIndicator.x = position.x - touchIndicator.width / 2;
        touchIndicator.y = position.y - touchIndicator.height / 2;
        touchIndicator.visible = true;
    }

    visible: true
    width: 640
    height: 640

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: { "item": "qrc:/MainPage.qml", "properties":{ "stackView":  stackView }}
        delegate:stackViewDelegate
    }

    StackViewDelegate {
        id: stackViewDelegate

        function finishedTrasition(properties) {
            properties.exitItem.scale = 1.0;
        }


        pushTransition: StackViewTransition {


            PropertyAnimation {
                target: exitItem
                property: "scale"
                from: 1.0
                to: 0.0
                duration: 1000
            }
            PropertyAnimation {
                target: enterItem
                property: "scale"
                from: 0.0
                to: 1.0
                duration: 1000
            }
        }
    }

    TouchIndicator {
        id: touchIndicator
        z: 1
        visible: false
    }
}
