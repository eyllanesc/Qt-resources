/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "readonlymodel.h"

#include "node.h"

ReadOnlyModel::ReadOnlyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

ReadOnlyModel::~ReadOnlyModel()
{
    delete m_root;
}

void ReadOnlyModel::setRootNode(Node *root)
{
    beginResetModel();
    m_root = root;
    endResetModel();
}

QModelIndex ReadOnlyModel::index(int row, int column, const QModelIndex &parent) const
{
    if(hasIndex(row, column, parent)) {
        Node *parentNode = nodeForIndex(parent);
        Node *childNode = parentNode->children.at(row);
        return createIndex(row, column, childNode);
    }
    return QModelIndex();
}

QModelIndex ReadOnlyModel::parent(const QModelIndex &child) const
{
    Node *childNode = nodeForIndex(child);
    Node *parentNode = childNode->parent;

    if(parentNode == m_root) {
        return QModelIndex();
    }
    int row = rowForNode(parentNode);
    int column = 0;
    return createIndex(row, column, parentNode);
}

int ReadOnlyModel::rowCount(const QModelIndex &parent) const
{
    Node *parentNode = nodeForIndex(parent);
    return parentNode->children.count();
}

int ReadOnlyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant ReadOnlyModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && role == Qt::DisplayRole) {
        Node *node = nodeForIndex(index);
        return node->data();
    }
    return QVariant();
}

QModelIndex ReadOnlyModel::indexForNode(Node *node) const
{
    if(node == m_root) {
        return QModelIndex();
    }
    int row = rowForNode(node);
    int column = 0;
    return createIndex(row, column, node);
}

Node *ReadOnlyModel::nodeForIndex(const QModelIndex &index) const
{
    if(index.isValid()) {
        return static_cast<Node*>(index.internalPointer());
    }
    return m_root;
}

int ReadOnlyModel::rowForNode(Node *node) const
{
    return node->parent->children.indexOf(node);
}




