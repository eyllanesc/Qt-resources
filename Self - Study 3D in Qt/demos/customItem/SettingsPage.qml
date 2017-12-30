import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Rectangle {
    property var stackView

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

    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a QML file")
        folder: Qt.resolvedUrl(".")
        onAccepted: {
            loader.sourceComponent = Qt.createComponent(fileDialog.fileUrls[0]);
        }
    }

    Column {
        anchors.right: parent.right
        Button {
            text: "+"
            onClicked: fileDialog.open();
        }
        Button {
            text: "-"
            onClicked: stackView.pop();
        }
    }

    Loader {
        id: loader
        anchors { top: parent.top; left: parent.left; topMargin: 20; leftMargin: 20 }
    }
}
