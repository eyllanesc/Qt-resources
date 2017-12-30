/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QtGui/QStandardItemModel>

#include "cityengine.h"

class CityModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit CityModel(QObject *parent = Q_NULLPTR);

private:
    void setupModel();
};

#endif // CITYMODEL_H
