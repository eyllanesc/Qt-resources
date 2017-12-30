/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "data.h"
#include <QDebug>
Data::Data()
    : m_intPointer(new int(0))
{
}

// Copy constructor needed for deep copy
Data::Data(const Data &another)
{
    m_string = another.m_string;
    m_intPointer = new int(*another.m_intPointer);
}

Data::~Data()
{
    delete m_intPointer;
}

const QString &Data::string() const
{
    return m_string;
}

void Data::setString(const QString &string)
{
    m_string = string;
}

int Data::value() const
{
    return *m_intPointer;
}

void Data::setValue(int value)
{
    *m_intPointer = value;
}

QDataStream &operator<<(QDataStream &stream, const Data &data)
{
    stream << data.string() << QString::number(data.value());

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Data &data)
{
    QString string, value;
    stream >> string >> value;
    data.setString(string);
    data.setValue(value.toInt());

    return stream;
}
