/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

// #define USE_VARIANT

#include <QTemporaryFile>
#include <QDataStream>
#include <QDebug>
#include "data.h"

int main(int, char *[])
{
    Data data;
    data.setString("Hello World");
    data.setValue(42);

    QTemporaryFile file;
    if (!file.open()) {
        qDebug() << "Temp file opening failed.";
        return EXIT_FAILURE;
    }

    QDataStream stream(&file);
    // If a custom type is searilzed using QVariant,
    // serialization operators need to be provided
#ifdef USE_VARIANT
    qRegisterMetaTypeStreamOperators<Data>("Data");
    QVariant variantData(QVariant::fromValue(data));
    stream << variantData;
#else
    stream << data;
#endif

    file.reset();

    // Serialize from the file
    Data dataFromFile;
#ifdef USE_VARIANT
    QVariant variantFromFile;
    stream >> variantFromFile;
    dataFromFile.setString(variantFromFile.value<Data>().string());
    dataFromFile.setValue(variantFromFile.value<Data>().value());
#else
    stream >> dataFromFile;
#endif
    qDebug() << dataFromFile.string();
    qDebug() << dataFromFile.value();

    file.close();

    return EXIT_SUCCESS;
}
