/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include <QString>

int main(int, char *[])
{
    QVariant variant(123);

    qDebug() << variant.typeName() << variant.userType(); // int 2
    qDebug() << variant.toInt() << variant.value<int>(); // 123 123

    variant = QVariant(QObject::tr("hello"));
    if (variant.canConvert<int>())
        qDebug() << variant.toInt(); // 0

    QString string = QStringLiteral("123");
    variant = QVariant::fromValue<QString>(string);
    qDebug() << variant.toInt(); // 123
}
