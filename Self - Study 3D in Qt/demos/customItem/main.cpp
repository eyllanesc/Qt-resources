#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QQuickWindow>
#include <QQmlContext>
#include "customitem.h"
#include "customview.h"
#include "backgroundpainter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CustomItem> ("DemoItems", 1, 0, "DemoItem");

    CustomView view;

    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.setObserver(view.rootObject());
    view.setClearBeforeRendering(false);
    BackgroundPainter painter(&view);
    view.rootContext()->setContextProperty("background", &painter);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
