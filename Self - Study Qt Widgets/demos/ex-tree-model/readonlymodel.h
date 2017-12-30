/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef READONLYMODEL_H
#define READONLYMODEL_H

#include <QtWidgets>

class Node;

class ReadOnlyModel : public QAbstractItemModel
{
public:
    explicit ReadOnlyModel(QObject *parent = Q_NULLPTR);
    ~ReadOnlyModel();
    QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    void setRootNode(Node *root);
    Node* rootNode() const;
protected:
    QModelIndex indexForNode(Node *node) const;
    Node* nodeForIndex(const QModelIndex &index) const;
    int rowForNode(Node *node) const;
protected:
    Node *m_root;
};

#endif // READONLYMODEL_H
