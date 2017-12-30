/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtCore>

bool operator<(const QPoint& p1, const QPoint& p2)
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

bool isSubString(const QString &string) { return string.contains("hello"); }

int main(int, char *[])
{
    QMap<QPoint, QString> container;

    // Fill in the container
    QString item("Item ");
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            container.insert(QPoint(x, y), item + QString::number(100 * x + y));
        }
    }

    // Print out the result
    QMapIterator<QPoint, QString> iterator(container);
    while (iterator.hasNext()) {
        qDebug() << iterator.next().value();
    }

    // Remove every third element from the container
    QMutableMapIterator<QPoint, QString> mutableIterator(container);
    int count(1);
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 3) == 0) {
            mutableIterator.remove();
        }
    }

    // Print out the result
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        qDebug() << mutableIterator.next().value();
    }

    // Set the value of every fifth element to hello n
    count = 1;
    QString hello("hello ");
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 5) == 0) {
            mutableIterator.setValue(hello + QString::number(count));
        }
    }

    // Print out the result
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        qDebug() << mutableIterator.next().value();
    }

    // Calculate how many times "hello" sub-string is included in the container
    qDebug() << std::count_if(container.begin(), container.end(), isSubString);
}
