/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "editablemodel.h"
#include "node.h"

EditableModel::EditableModel(QObject *parent) :
    ReadOnlyModel(parent)
{
}

EditableModel::~EditableModel()
{
}

bool EditableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole) {
        Node *node = nodeForIndex(index);
        node->text = value.toString();
        QModelIndex topLeft = index;
        QModelIndex bottomRight = index;
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}

Qt::ItemFlags EditableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = ReadOnlyModel::flags(index);
    if(index.isValid()) {
        return Qt::ItemIsEditable | defaultFlags;
    }
    return defaultFlags;
}
