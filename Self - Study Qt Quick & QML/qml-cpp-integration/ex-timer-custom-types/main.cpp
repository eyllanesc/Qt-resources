/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "timer.h"
#include "IntervalSettings.h"

#include <QDateTime>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h> // for qmlRegisterType

int main(int argc, char *argv[])
{
    QGuiApplication app( argc, argv );

    qsrand( QDateTime::currentMSecsSinceEpoch() );

    // Expose the Timer class
    qmlRegisterType<Timer>( "CustomComponents", 1, 0, "Timer" );
    qmlRegisterType<IntervalSettings>( "CustomComponents", 1, 0, "IntervalSettings");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
