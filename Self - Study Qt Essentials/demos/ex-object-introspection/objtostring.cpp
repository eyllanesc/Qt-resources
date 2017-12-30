/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QApplication>

// Creates a string, describing an object, using meta-object introspection
QString objToString(const QObject *obj) {
    QStringList result;
    const QMetaObject *meta = obj->metaObject();
    result += QString("class %1 : public %2 {").arg(meta->className())
            .arg(meta->superClass()->className());
    for (auto i=0; i < meta->propertyCount(); ++i) {
        const QMetaProperty property = meta->property(i);
        QVariant value = obj->property(property.name());
        if (value.canConvert(QVariant::String))
            result += QString("  %1 %2 = %3;")
                    .arg(property.typeName())
                    .arg(property.name())
                    .arg(value.toString());
    }

    QString signalPrefix("");
    for (auto i=0; i < meta->methodCount(); ++i) {
        const QMetaMethod method = meta->method(i);
        const QMetaMethod::MethodType methodType = method.methodType();
        if (methodType == QMetaMethod::Signal)
            signalPrefix = QStringLiteral("Q_SIGNAL");
        else if (methodType == QMetaMethod::Slot)
            signalPrefix = QStringLiteral("Q_SLOT");
        result += QString("  %1 %2 %3;")
                .arg(signalPrefix)
                .arg(QVariant::typeToName(method.returnType()))
                .arg(QString(method.methodSignature()));
    }
    result += "};";
    return result.join("\n");
}

int main (int argc, char *argv[]) {
    QApplication application(argc, argv);
    application.setOrganizationName("The Qt Company");
    application.setApplicationName("testproperties");
    application.setOrganizationDomain("qt.io");
    QWindow window;
    qDebug() << objToString(&application);
    qDebug() << objToString(&window);

}

