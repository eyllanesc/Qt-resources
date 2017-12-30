/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TRANSFORMATIONITEM_H
#define TRANSFORMATIONITEM_H

#include <QListWidgetItem>
#include <QMetaEnum>

class QGraphicsItem;

/** A transform operation that can be sequenced with other items to produce
    an animation */
class TransformationItem : public QObject, public QListWidgetItem
{
    Q_OBJECT
    Q_PROPERTY(Operation operation READ operation WRITE setOperation)
public:
    TransformationItem(QObject* parent = Q_NULLPTR);
    enum Operation {NONE=0, ROTATE=1, SCALE=2, TRANSLATE=3, MATRIX=4, SHEAR=5} ;
    Q_ENUMS(Operation);

    /** Apply this transform operation on an item */
    virtual void apply(QGraphicsItem * item);

    /** Perform the reverse of the transformation on the item */
    virtual void reverseApply(QGraphicsItem *item);

    // Setters

    void rotate(qreal angle, Qt::Axis axis = Qt::ZAxis);
    void scale (qreal x, qreal y);
    void shear (qreal h, qreal v);
    void translate(qreal x, qreal y);
    void setMatrix(QTransform matrix);
    void setOperation(Operation op);

    // Getters
    QString operationStr() const;
    Operation operation() const {return m_operation;}
    QStringList operations() const;
    double x() const {return m_x;}
    double y() const {return m_y;}
    double angle() const {return m_angle;}
    Qt::Axis axis() const {return m_axis;}
    QTransform matrix() const {return m_matrix;}

protected:
    void updateText();


private:
    Operation m_operation;
    double m_x, m_y;
    double m_angle;
    Qt::Axis m_axis;
    QTransform m_matrix;
    QTransform m_old;
    QMetaEnum m_enum;


};

#endif // TRANSFORMATIONITEM_H
