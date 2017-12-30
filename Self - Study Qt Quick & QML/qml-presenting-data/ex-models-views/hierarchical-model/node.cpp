/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "node.h"

Node::Node(const QString& aText, Node *aParent)
    : text(aText), parent(aParent)
{
    if(parent) {
        parent->children.append(this);
    }
}

Node::~Node()
{
    qDeleteAll(children);
}

QVariant Node::data() const {
    return text;
}
