import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    property var stackView
property string pageType: "hello"
    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#a6a1a1";
        }
        GradientStop {
            position: 1.00;
            color: "#ffffff";
        }
    }

    Column {
        anchors.right: parent.right
        Button {
            text: "Settings"
            onClicked: stackView.push({item: "qrc:/SettingsPage.qml", properties: {stackView: stackView}});
        }

        Button {
            text: "View page"
            onClicked: stackView.push({item: "qrc:/ViewPage.qml", properties: {stackView: stackView}});
        }
    }
}
