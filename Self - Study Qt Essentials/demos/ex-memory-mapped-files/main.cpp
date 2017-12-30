/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QFile>
#include <QtDebug>

#define PRIVATE_MAPPING

int main(int argc, char *argv[])
{
    if (argc < 2) {
        qWarning() << QString("Usage: %1 textFile").arg(argv[0]);
        return EXIT_FAILURE;
    }
    QFile file(argv[1]);
    if (!file.open(QFile::ReadWrite | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << file.fileName();
        return EXIT_FAILURE;
    }

#ifndef PRIVATE_MAPPING
    uchar *mappedPointer = file.map(0, file.size());
#else
    uchar *mappedPointer = file.map(0, file.size(), QFile::MapPrivateOption);
#endif
    QByteArray array(reinterpret_cast<char *>(mappedPointer));
    array.replace("Dickens", "DICKENS");
    memcpy(mappedPointer, array.constData(), file.size());

    file.unmap(mappedPointer);
    file.close();

    qDebug() << "Look at changes in" << file.fileName();

    return EXIT_SUCCESS;
}
