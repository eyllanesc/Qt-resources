/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAPCONTROLLERITEM_H_
#define MAPCONTROLLERITEM_H_

#include <QtWidgets/QGraphicsWidget>

class QSlider;

class MapControllerItem : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit MapControllerItem(QGraphicsItem *p = Q_NULLPTR, Qt::WindowFlags flags = 0);
	~MapControllerItem();
	
Q_SIGNALS:
    void zoomChanged(int percents);
    
private Q_SLOTS:
    void zoomIn();
    void zoomOut();
    
private:
    QSlider *m_zoomSlider;
};

#endif /*MAPCONTROLLERITEM_H_*/
