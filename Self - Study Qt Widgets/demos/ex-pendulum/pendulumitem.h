/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PENDULUMITEM_H
#define PENDULUMITEM_H

#include <QtWidgets/QGraphicsItemGroup>

class QGraphicsLineItem;
class QGraphicsEllipseItem;

class PendulumItem : public QGraphicsItemGroup {
public:
  PendulumItem( QGraphicsItem* parent=0);
  virtual ~PendulumItem();
private:
	QGraphicsLineItem* m_rod;
	QGraphicsEllipseItem* m_weight;
};

#endif /* PENDULUMITEM_H */

