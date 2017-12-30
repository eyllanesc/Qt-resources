/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "citymodel.h"

enum ItemRoles {
    CityRole = Qt::UserRole + 1,
    CountryRole,
    PopulationRole,
    AreaRole,
    FlagRole
};


CityModel::CityModel(QObject *parent) : QStandardItemModel(parent)
{
    setupModel();
}

void CityModel::setupModel()
{
    CityEngine engine;

    // TODO fill data from engine into the model
    // hint: QStandardItem::setData() can be used to store more than one
    // value within an item
}
