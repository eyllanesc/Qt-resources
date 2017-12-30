/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAPVIEWERITEM_H
#define MAPVIEWERITEM_H

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsPixmapItem>

class MapViewerItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    
public:
    explicit MapViewerItem(QGraphicsItem *p = Q_NULLPTR);
    ~MapViewerItem();

public Q_SLOTS:
    void zoom(int percent);
    
};

#endif // MAPVIEWERITEM_H
