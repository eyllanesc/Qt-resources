/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EDITABLEMODEL_H
#define EDITABLEMODEL_H

#include <QtWidgets>
#include "readonlymodel.h"

class EditableModel : public ReadOnlyModel
{
public:
    explicit EditableModel(QObject *parent = Q_NULLPTR);
    ~EditableModel();
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // EDITABLEMODEL_H
