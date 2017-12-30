/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PICTUREITEM_H
#define PICTUREITEM_H

#include <QtCore/QList>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtCore/QRect>


class CornerItem;

class PictureItem : public QGraphicsItem {
public:
    PictureItem(QString fileName, QGraphicsItem* parent=0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE {
        return m_contentsRect;
    }
    void resetContentsRatio();
    void resizeContents(const QRect & rect, bool keepRatio = false);
    int contentHeightForWidth(int width) const;
    void layoutChildren();

    // rotation
    void setRotation(double angle, Qt::Axis axis = Qt::ZAxis);
    double rotation(Qt::Axis axis = Qt::ZAxis) const;
    void applyRotations();
    QRect contentsRect() const;
    ~PictureItem();

private:
    void createCorner(Qt::Corner corner);
    void addCornerButtons();
    QPixmap             m_pixmap;
    QList<CornerItem *> m_cornerItems;
    double              m_xRotationAngle;
    double              m_yRotationAngle;
    double              m_zRotationAngle;
    QRect               m_contentsRect;
};

#endif        //  #ifndef PICTUREITEM_H

