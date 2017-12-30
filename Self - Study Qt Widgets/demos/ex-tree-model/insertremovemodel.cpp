/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "insertremovemodel.h"

#include "node.h"

InsertRemoveModel::InsertRemoveModel(QObject *parent)
    : EditableModel(parent) {
}

InsertRemoveModel::~InsertRemoveModel()
{
}

void InsertRemoveModel::insertNode(Node *parentNode, int pos, Node *node)
{
    const QModelIndex parent = indexForNode(parentNode);
    int firstRow = pos;
    int lastRow = pos;

    beginInsertRows(parent, firstRow, lastRow);
    parentNode->children.insert(pos, node);
    endInsertRows();
}

void InsertRemoveModel::removeNode(Node *node)
{
    Node *parentNode = node->parent;
    const QModelIndex parent = indexForNode(parentNode);
    int pos = rowForNode(node);
    int firstRow = pos;
    int lastRow = pos;
    beginRemoveRows(parent, firstRow, lastRow);
    parentNode->children.removeAt(pos);
    endRemoveRows();
}

void InsertRemoveModel::removeAllNodes()
{
    beginResetModel();
    m_root->children.clear();
    endResetModel();
}
