/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <QtCore>

class Node
{
public:
    Node(const QString& aText="No Data", Node *aParent = Q_NULLPTR);
    ~Node();
    QVariant data() const;

    // Public data members
    QString text;
    Node *parent;
    QList<Node*> children;
};

#endif // NODE_H
