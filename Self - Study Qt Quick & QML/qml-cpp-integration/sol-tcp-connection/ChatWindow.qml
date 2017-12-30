/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import TCP 1.0

Item {
    property alias type : tcpConnection.type
    property alias port : tcpConnection.port
    property alias hostName : tcpConnection.hostName

    TcpConnectionElement {
        id : tcpConnection
        onDataReceived : {
            output.text += ">>>> " + data
        }
    }

    Component.onCompleted: tcpConnection.initialize()

    Rectangle {
        color: "#9c9898"; border.width: 0; border.color: "#000000"; anchors.fill: parent
    }

    Text {
        id : title
        text: titleText()
        anchors { top : parent.top; left : parent.left; right : parent.right }
        height : 30
    }

    Display {
        id: output
        anchors { top : title.bottom; left : parent.left; right : parent.right; bottom : entryRect.top }
        anchors.bottomMargin: 2
    }

    LineEdit {
        id: entryRect
        x: 0; y: 83; width: 100; height: 50
        focus: true
        anchors { bottom : parent.bottom; left : parent.left; right : parent.right; }

        onTextEntered: {
            output.text += "Me > " + text + "\n"
            tcpConnection.sendData(text)
        }
    }

    function titleText() {
        return (tcpConnection.type == TcpConnectionElement.Server ? "Server" : "Client")
                + " (" + hostName + ": " + port + ")"
    }
}
