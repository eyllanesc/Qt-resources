/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DNDMODEL_H
#define DNDMODEL_H

#include <QtWidgets>

#include "insertremovemodel.h"

class DndModel : public InsertRemoveModel
{
public:
    explicit DndModel(QObject *parent = Q_NULLPTR);
    ~DndModel();

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    Qt::DropActions supportedDragActions() const Q_DECL_OVERRIDE;
    Qt::DropActions supportedDropActions() const Q_DECL_OVERRIDE;
    QStringList mimeTypes() const Q_DECL_OVERRIDE;
    QMimeData *mimeData(const QModelIndexList &indexes) const Q_DECL_OVERRIDE;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                      int row, int column, const QModelIndex &parent) Q_DECL_OVERRIDE;

    bool removeRows(int row, int count, const QModelIndex &parent) Q_DECL_OVERRIDE;
//    bool insertRows(int row, int count, const QModelIndex &parent);
};

#endif // DNDMODEL_H
