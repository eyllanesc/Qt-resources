/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QMetaType>

class Contact
{
public:
    Contact();
    void setName(const QString name);
    QString name() const;

    bool operator != (const Contact &) const;

private:
    QString m_name;
};

Q_DECLARE_METATYPE(Contact)



#endif // CONTACT_H
