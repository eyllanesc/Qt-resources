/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QThread>
#include <QMetaType>
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    qMetaTypeId<Data>();

    Sender sender;
    Receiver receiver;
    QObject::connect(&sender, &Sender::data, &receiver, &Receiver::data);
    QObject::connect(&sender, &Sender::data2, &receiver, &Receiver::data2);

    // The connection below takes care we finish the thread nicely, when the window is closed
    QObject::connect(&sender, &Sender::closed, &receiver, &Receiver::quit);

    QThread thread;
    // Let's make the receiver running in the created thread
    receiver.moveToThread(&thread);
    thread.start();

    sender.show();
    return app.exec();
}

