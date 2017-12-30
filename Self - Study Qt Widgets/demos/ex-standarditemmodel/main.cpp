/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QStandardItem>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QStandardItemModel model;
    for (int row = 0; row < 10; ++row) {
        QList<QStandardItem*> columnItems;

        for (int col = 0; col < 10; ++col) {
            QStandardItem *item = new QStandardItem( QString("(%1, %2)").arg(row).arg(col));
            columnItems << item;
        }

        model.appendRow(columnItems);
    }


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("model_", &model);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
