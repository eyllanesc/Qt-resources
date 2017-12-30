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
#include <QQmlContext>
#include "node.h"
#include "readonlymodel.h"

Node *createData() {
    Node *root = new Node("Root");
    for(int i=0; i<10; i++) {
        Node *node1 = new Node(QString("Item %1").arg(i), root);
        for(int ii=0; ii<5; ii++) {
            Node *node2 = new Node(QString("Item %1/%2").arg(i).arg(ii), node1);
            for(int iii=0; iii<3; iii++) {
                new Node(QString("Item %1/%2/%3").arg(i).arg(ii).arg(iii), node2);
            }
        }
    }
    return root;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ReadOnlyModel *model = new ReadOnlyModel(&app);
    Node *root = createData();
    model->setRootNode(root);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("delegateModel", model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
