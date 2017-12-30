/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "dndmodel.h"

#include "node.h"

DndModel::DndModel(QObject *parent)
    : InsertRemoveModel(parent)
{
}

DndModel::~DndModel()
{
}

Qt::ItemFlags DndModel::flags(const QModelIndex &index) const
{
    if(index.isValid()) {
        return Qt::ItemIsDragEnabled
                | Qt::ItemIsDropEnabled
                | InsertRemoveModel::flags(index);
    }
    // allow dropping in empty area (invalid index)
    return Qt::ItemIsDropEnabled | InsertRemoveModel::flags(index);
}

Qt::DropActions DndModel::supportedDragActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

Qt::DropActions DndModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

QStringList DndModel::mimeTypes() const
{
    QStringList types;
    types << "application/vnd.text.list";
    return types;

}

QMimeData *DndModel::mimeData(const QModelIndexList &indexes) const
{
    QByteArray encodedData;
    QDataStream stream(&encodedData, QIODevice::WriteOnly);
    for (const QModelIndex &index : indexes) {
        if(index.isValid()) {
            QString text = data(index, Qt::DisplayRole).toString();
            stream << text;
        }
    }
    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/vnd.text.list", encodedData);
    return mimeData;
}

bool DndModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if(action == Qt::IgnoreAction) {
        return true;
    }
    if(!data->hasFormat("application/vnd.text.list")) {
        return false;
    }
    if(column >= columnCount(parent)) {
        return false;
    }
    Node *parentNode = nodeForIndex(parent);
    QByteArray encodedData = data->data("application/vnd.text.list");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    while(!stream.atEnd()) {
        QString text;
        stream >> text;
        Node *node = new Node(text, parentNode);
        insertNode(parentNode, row, node);
    }
    return true;
 }

bool DndModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+count);
    Node *parentNode = nodeForIndex(parent);
    for(int i=0; i<count; i++) {
        if(row < parentNode->children.count()) {
            Node *node = parentNode->children.at(row);
            parentNode->children.removeAt(row);
            node->parent = 0;
        }
    }
    endRemoveRows();
    return true;
}

//bool DndModel::insertRows(int row, int count, const QModelIndex &parent)
//{
//    beginInsertRows(parent, row, row+count);
//    Node *parentNode = nodeForIndex(parent);
//    for(int i=0; i<count; i++) {
//        new Node("No Data", parentNode);
//    }
//    endInsertRows();
//    return true;
//}

