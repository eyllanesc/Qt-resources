/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CORNERITEM_H
#define CORNERITEM_H

#include <QtWidgets/QGraphicsRectItem>

class PictureItem;

class CornerItem : public QGraphicsRectItem
{
public:
    explicit CornerItem(Qt::Corner corner, PictureItem *parent = Q_NULLPTR);
    void relayout(const QRect & rect);

    // ::QGraphicsItem reimplements:

    // Uncomment next lines
    //    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    //    void mousePressEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    //    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    //    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_OVERRIDE;


private:
    enum Operation {
        Off         = 0x0000,
        Rotate      = 0x0001,
        FixRotate   = 0x0002,
        Scale       = 0x0010,
        FixScale    = 0x0020,
        AllowAll    = 0xFFFF,
    };
    PictureItem *m_content;
    Qt::Corner m_corner;
    int m_size;

    int m_operation;
    double m_startRatio;

};

#endif // CORNERITEM_H

