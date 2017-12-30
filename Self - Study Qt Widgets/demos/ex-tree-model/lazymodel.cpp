/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "lazymodel.h"

#include "node.h"

LazyModel::LazyModel(QObject *parent)
    : ReadOnlyModel(parent)
{
}

LazyModel::~LazyModel()
{
}

bool LazyModel::hasChildren(const QModelIndex &parent) const
{
    int depth = 0;
    Node *parentNode = nodeForIndex(parent);
    while(parentNode) {
        parentNode = parentNode->parent;
        ++depth;
    }
    return (depth <=3);
}

bool LazyModel::canFetchMore(const QModelIndex &parent) const
{
    static const int maxChildren = 100;
    Node *parentNode = nodeForIndex(parent);
    return parentNode->children.count() < maxChildren;
}

void LazyModel::fetchMore(const QModelIndex &parent)
{
    static const int maxChildren = 100;
    Node *parentNode = nodeForIndex(parent);
    int count = parentNode->children.count();
    if(count < maxChildren) {
        beginInsertRows(parent, count, maxChildren-count);
        while(parentNode->children.count() < maxChildren) {
            new Node("Lazy Node", parentNode);
        }
        endInsertRows();
    }
}
