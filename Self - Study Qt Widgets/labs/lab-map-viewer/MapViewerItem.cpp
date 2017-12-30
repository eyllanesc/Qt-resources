/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MapViewerItem.h"

#include <QtGui/QTransform>

MapViewerItem::MapViewerItem(QGraphicsItem *p)
  : QObject(0), QGraphicsPixmapItem( QPixmap(":/Groland_map.png"), p)
{
    setZValue(-10);
    setOffset(-pixmap().width() / 2, -pixmap().height() / 2);
    setTransformationMode(Qt::SmoothTransformation);
    setFlag(QGraphicsItem::ItemIsMovable);
}

MapViewerItem::~MapViewerItem()
{
}

void MapViewerItem::zoom( int percent )
{
    double zoomFactor = percent / 100.0 ;
    setTransform(QTransform().scale(zoomFactor, zoomFactor));
}
