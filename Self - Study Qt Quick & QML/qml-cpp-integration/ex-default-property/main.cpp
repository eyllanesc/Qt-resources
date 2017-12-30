/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "baritem.h"
#include "chartitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ChartItem>("Shapes", 8, 0, "Chart");
    qmlRegisterType<BarItem>("Shapes", 8, 0, "Bar");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/chart1.qml")));

    return app.exec();
}
