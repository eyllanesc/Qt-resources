/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QMetaType>

class Data
{
public:
    Data();
    Data(const Data &);
    ~Data();

    const QString &string() const;
    void setString(const QString &);
    int value() const;
    void setValue(int);

private:
    QString m_string;
    int *m_intPointer;
};

Q_DECLARE_METATYPE(Data)

QDataStream & operator<< (QDataStream& stream, const Data& data);
QDataStream & operator>> (QDataStream& stream, Data& data);

#endif // DATA_H
