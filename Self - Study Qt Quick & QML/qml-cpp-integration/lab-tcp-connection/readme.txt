Step 1
======
First thing is to be able to create an instance of the TcpConnectionElement
from the QML side.

For that you need to:
* register the C++ class using qmlRegisterType
* import it on the QML Side
* Create an instance of it on the QML side (in the element ChatWindow)

Once you have created an instance of it, it should print "Yes I'm alive!",
and start listening on port 4242 on localhost. You may try the server by
running the solution as a client.

Step 2
======
Next step is to receive data from the TCP element, and insert it into the
output window.

Hint: Look for signals on the TcpConnectionElement.

Step 3
======
Now make it possible to send data from your end to the other end.

Step 4
======
So far the port, host address, and server type have been hard coded in the
C++ file.

The goal is to be able to specify these in Client.qml and Server.qml.
We will rework this in three steps.

First step is to add the properties on the TcpConnectionElement
class. The class already have a number of setters and getters for your
convenience.

You can debug this by simply setting the properties on the
TcpConnectionElement in ChatWindow.qml

First add the port and host name, then the type.

Hint: The type is an enum, that needs to be wrapped in Q_ENUMS.

Step 5:
=======
Next step is to be able to specify these enums from Server.qml and
Client.qml

Hint: the hostName for the server should be "127.0.0.1"

Hint: The properties should exists on the ChatWindow element, but they
should just be redirected to the TcpConnectionElement.

Also, update the titleText() function to return something like 
"Server on localhost(4242)", where it of course uses the real values

Step 6:
=======
The TcpConnectionElement is currently not using the new properties. Make it
do so.

Hint: The problem at hand is that the class is set up in the constructor,
that won't work anymore, so move the constructor to a method that is called
once the class has been set up

Hint: You can call this method using code like this in the ChatWindow:
Component.onCompleted: tcpConnection.initialize()

Optional step:
==============
Add an enum in C++ which contains the state of the connection,
and only enable the line edit when it is enabled.
