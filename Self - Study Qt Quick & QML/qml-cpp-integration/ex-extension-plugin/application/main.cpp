/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QDir>
#include <QQmlExtensionPlugin>
#include <QQmlApplicationEngine>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QDir pluginsDir(app.applicationDirPath() + "/plugins");
    for (const QString &fileName: pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QQmlExtensionPlugin *plugin = qobject_cast<QQmlExtensionPlugin *>(loader.instance());
        if (plugin)
            plugin->registerTypes("Shapes");
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/files/ellipse9.qml")));
    return app.exec();
}
