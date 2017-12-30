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

    const auto fileSize(file.size());
    QByteArray readBuffer;

    // Read file character by character
    char c;
    while (file.getChar(&c))
        readBuffer.append(c);
    qDebug() << readBuffer;

    // Read line by line
    readBuffer.clear();
    file.reset();
    while (!file.atEnd())
        readBuffer = file.readLine(fileSize);
    qDebug() << readBuffer;

    // Read data by chunks
    readBuffer.clear();
    file.reset();
    const int bufferSize(10); // Intentionally extremely small for demo purposes
    char chunk[bufferSize];
    auto readBytes(0);
    while ((readBytes = file.read(chunk, bufferSize)) > 0)
        readBuffer.append(chunk, readBytes);
    qDebug() << readBuffer;

    // Read all
    // Avoid, if file size is large or unknown
    readBuffer.clear();
    file.reset();
    readBuffer = file.readAll();
    qDebug() << readBuffer;

    QByteArray writeBuffer("Some random data");
    if (file.write(writeBuffer.data()) != writeBuffer.length())
        qWarning() << "Error in writing to file" << file.fileName();

    // File size changes
    qDebug() << "Original file size" << fileSize << "New file size" << file.size();
    qDebug() << "Bytes available" << file.bytesAvailable();
    file.reset();
    qDebug() << "Bytes available after file reset" << file.bytesAvailable();

    readBuffer.clear();
    readBuffer = file.readAll();
    qDebug() << readBuffer;

    file.close();

    return EXIT_SUCCESS;
}
