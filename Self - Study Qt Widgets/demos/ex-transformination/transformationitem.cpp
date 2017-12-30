/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QMetaProperty>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "transformationitem.h"

TransformationItem::TransformationItem(QObject* parent) :  QObject(parent),
    m_operation(NONE), m_x(0), m_y(0), m_angle(0), m_axis(Qt::ZAxis) {
    updateText();


    int idx = metaObject()->indexOfProperty("operation");
    QMetaProperty mprop = metaObject()->property(idx);
    m_enum = mprop.enumerator();

}


QString TransformationItem::operationStr() const {
    return m_enum.valueToKey(m_operation);
}

QStringList TransformationItem::operations() const {
    QStringList retval;
    for (int i=0; i<m_enum.keyCount(); ++i) {
        retval << m_enum.valueToKey(i);
    }
    return retval;
}

void TransformationItem::updateText() {
    QString op = operationStr();
    //    setText(op);
    QString paramString;
    switch (m_operation) {
    case TRANSLATE:
    case SHEAR:
    case SCALE: paramString = QString("%1, %2").arg(m_x).arg(m_y);
        break;
    case ROTATE: paramString = QString("%1, %2").arg(m_angle).arg(m_axis);
        break;
    case MATRIX: paramString = QString("matrix");
        break;
    default: paramString=QString();
        break;

    }
    setText(QString("%1(%2)").arg(op).arg(paramString));
}


void TransformationItem::rotate(qreal angle, Qt::Axis axis) {
    setOperation(ROTATE);
    m_angle = angle;
    m_axis = axis;
    updateText();
}

void TransformationItem::scale (qreal x, qreal y) {
    setOperation(SCALE);
    m_x = x;
    m_y = y;
    updateText();
}

void TransformationItem::shear (qreal h, qreal v) {
    setOperation(SHEAR);
    m_x = h;
    m_y = v;
    updateText();

}

void TransformationItem::translate(qreal x, qreal y) {
    setOperation(TRANSLATE);
    m_x = x;
    m_y = y;
    updateText();
}

void TransformationItem::setOperation(Operation op) {
    m_operation = op;
    switch (m_operation) {
    case MATRIX: setIcon(QIcon(":/images/transform.png"));
        break;
    case SCALE: setIcon(QIcon(":/images/scale.png"));
        break;
    case ROTATE: setIcon(QIcon(":/images/rotate.png"));
        break;
    case SHEAR: setIcon(QIcon(":/images/shear.png"));
        break;
    case TRANSLATE: setIcon(QIcon(":/images/translate.png"));
        break;
    default: break;
    }
}

void TransformationItem::setMatrix(QTransform matrix) {
    setOperation(MATRIX);
    m_matrix = matrix;
    updateText();

}

void TransformationItem::reverseApply(QGraphicsItem * item) {

    if (item->transform() != m_old) {
        item->setTransform(m_old);
        return;
    }
    // Attempt a "reverse" operation, which can lead to rounding errors.
    QTransform transformed; // = item->transform();
    m_old = item->transform();
    switch (m_operation) {
    case ROTATE: transformed.rotate(m_angle, m_axis);
        break;
    case SHEAR: transformed.shear(m_x, m_y);
        break;
    case SCALE: transformed.scale(m_x, m_y);
        break;
    case TRANSLATE: transformed.translate(m_x, m_y);
        break;
    case MATRIX: transformed = m_matrix;
        break;
    default:
        break;
    }
    transformed = transformed.inverted();
    item->setTransform(m_old * transformed);

}


void TransformationItem::apply(QGraphicsItem* item) {
    m_old = item->transform();
    switch (m_operation) {

    case ROTATE: {
        QTransform t = item->transform();
        t.rotate(m_angle, m_axis);
        item->setTransform(item->transform() * t);
        break;
    }
    case SHEAR: {
        QTransform t = item->transform();
        t.shear(m_x, m_y);
        item->setTransform(item->transform() * t);
        break;
    }
    case SCALE: {
        QTransform t = item->transform();
        t.scale(m_x, m_y);
        item->setTransform(item->transform() * t);
        break;
    }
    case TRANSLATE: {
        QTransform t = item->transform();
        t.translate(m_x, m_y);
        item->setTransform(item->transform() * t);
        break;
    }
    case MATRIX: item->setTransform(item->transform() * m_matrix);
        break;
    default:
        break;
    }

}
