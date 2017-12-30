/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MapViewerItem.h"
#include "MapControllerItem.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QGraphicsScene scene(-300.0, -200.0, 600.0, 400.0); // centered on (0.0, 0.0)

    MapViewerItem *mapViewerItem = new MapViewerItem;
    scene.addItem(mapViewerItem);

    MapControllerItem* mapControllerItem = new MapControllerItem;
    scene.addItem( mapControllerItem );
    mapControllerItem->setGeometry(-280.0, -150.0, 20.0, 200.0);
    
    QObject::connect(mapControllerItem, &MapControllerItem::zoomChanged, mapViewerItem, &MapViewerItem::zoom);

    QGraphicsView view(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.resize(600,400);
    view.show();
    return app.exec();
}
