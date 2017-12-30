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

    MapViewerItem* mapViewerItem = new MapViewerItem;
    scene.addItem(mapViewerItem);
    
    // Add MapControllerItem to the scene

    QGraphicsView view(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.resize(600,400);
    view.show();
    return app.exec();
}
