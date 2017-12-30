/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "pictureitem.h"
#include "corneritem.h"


PictureItem::PictureItem(QString fileName, QGraphicsItem *parent)
{
    m_pixmap = QPixmap(fileName);

    m_contentsRect = m_pixmap.rect();
    addCornerButtons();
    setFlags(ItemIsMovable);
}


void PictureItem::addCornerButtons() {
    // create child controls
    createCorner(Qt::TopLeftCorner);
    createCorner(Qt::TopRightCorner);
    createCorner(Qt::BottomLeftCorner);
    createCorner(Qt::BottomRightCorner);
}

PictureItem::~PictureItem() {
    qDeleteAll(m_cornerItems);
}


void PictureItem::createCorner(Qt::Corner corner) {
    CornerItem * c = new CornerItem(corner, this);
    c->setVisible(true);
    c->setZValue(2.0);
    m_cornerItems.append(c);
}


void PictureItem::resetContentsRatio()
{
    resizeContents(m_contentsRect, true);
}


void PictureItem::resizeContents(const QRect & rect, bool keepRatio)
{
    if (!rect.isValid())
        return;

    prepareGeometryChange();

    QRect oldRect = m_contentsRect;
    m_contentsRect = rect;

    if (keepRatio) {
        int hfw = contentHeightForWidth(rect.width());
        if (hfw > 1) {
            m_contentsRect.setTop(-hfw / 2);
            m_contentsRect.setHeight(hfw);
        }
    }
    layoutChildren();
    update();

}

QRect PictureItem::contentsRect() const
{
    return m_contentsRect;
}


int PictureItem::contentHeightForWidth(int width) const
{
    if (m_contentsRect.width() < 1)
        return -1;
    return (m_contentsRect.height() * width) / m_contentsRect.width();
}

void PictureItem::layoutChildren() {
    // layout corners
  foreach (CornerItem * corner, m_cornerItems) {
        corner->relayout(m_contentsRect);
  }
}


void PictureItem::setRotation(double angle, Qt::Axis axis)
{
    switch (axis) {
        case Qt::XAxis: if (m_xRotationAngle == angle) return; m_xRotationAngle = angle; break;
        case Qt::YAxis: if (m_yRotationAngle == angle) return; m_yRotationAngle = angle; break;
        case Qt::ZAxis: if (m_zRotationAngle == angle) return; m_zRotationAngle = angle; break;
    }
    applyRotations();
}

double PictureItem::rotation(Qt::Axis axis) const
{
    switch (axis) {
        case Qt::XAxis: return m_xRotationAngle;
        case Qt::YAxis: return m_yRotationAngle;
        case Qt::ZAxis: return m_zRotationAngle;
    }
    // suppress warnings, can't reach here
    return 0.0;
}

void PictureItem::applyRotations()
{
    setTransform(QTransform().rotate(m_yRotationAngle, Qt::XAxis).rotate(m_xRotationAngle, Qt::YAxis).rotate(m_zRotationAngle));
}

void PictureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QRect targetRect = contentsRect();
    QPixmap photo = m_pixmap.scaled(targetRect.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter->setRenderHints(QPainter::SmoothPixmapTransform);
    painter->drawPixmap(targetRect.topLeft(), photo);
}



