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

#include <QObject>
class QString;

class Data
{
public:
    Data();
    Data(int integerArg, int *pointerArg, const QString &stringArg);

    int m_integer;
    int *m_pointer;
    QString m_string;

    bool operator != (const Data &) const;
};

Q_DECLARE_METATYPE(Data)

#endif // DATA_H
