/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QQuickItem>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

class TriangleItem : public QQuickItem
{
    Q_OBJECT

public:
    TriangleItem(QQuickItem *parent = Q_NULLPTR);

protected:
    QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *data) Q_DECL_OVERRIDE;

private:
    QSGGeometry m_geometry;
    QSGFlatColorMaterial m_material;
};

#endif
