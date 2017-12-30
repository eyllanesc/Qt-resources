/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

/** An Example QGraphicsItem that plots a coordinate system
    in its rectangular area. */
class CoordinateSystem : public QGraphicsItem {
public:
    explicit CoordinateSystem(QGraphicsItem* parent = Q_NULLPTR);
    void setRect(const QRectF& r);
    QRectF rect() const;

    void setText(const QString& txt);
    QString text() const;

    /** @return a shallow copy of this graphics item */
    CoordinateSystem *copy();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *w) Q_DECL_OVERRIDE;

    QPen edgePen() const       { return m_edgePen; }
    QBrush edgeBrush() const { return m_edgeBrush; }
    QPen axisPen() const       { return m_axisPen; }

private:
    QRectF m_rect;
    QPen m_edgePen;
    QBrush m_edgeBrush;
    QPen m_axisPen;
    QString m_text;
};


#endif /* COORDINATESYSTEM_H */

