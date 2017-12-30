/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef LAZYMODEL_H
#define LAZYMODEL_H

#include <QtWidgets>

#include "readonlymodel.h"

class LazyModel : public ReadOnlyModel
{
public:
    explicit LazyModel(QObject *parent = Q_NULLPTR);
    ~LazyModel();

    bool hasChildren(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    bool canFetchMore(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    void fetchMore(const QModelIndex &parent) Q_DECL_OVERRIDE;
};

#endif // LAZYMODEL_H
