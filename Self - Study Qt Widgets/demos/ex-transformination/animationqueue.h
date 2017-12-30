/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ANIMATIONQUEUE_H
#define ANIMATIONQUEUE_H

#include <QObject>
#include <QTransform>
#include <QTimeLine>
class CoordinateSystem;
class TransformationItem;

/** Applies a list of TransformationItem objects
    in sequence to an image.
*/
class AnimationQueue : public QObject
{
    Q_OBJECT
public:
    AnimationQueue(CoordinateSystem *graphicsObject, QObject* parent=Q_NULLPTR);
    void add(TransformationItem* i);
    void setItem(CoordinateSystem* a) {
        m_before = a;
    }
protected Q_SLOTS:
    void applyGradual(TransformationItem*);
    void advance(qreal);
    void finishAnimation();
Q_SIGNALS:
    void operationFinished();
    void animating(TransformationItem *);
private:
    QTimeLine m_timeLine;
    CoordinateSystem *m_before, *m_after;
    QList<TransformationItem*> m_queue;
    TransformationItem* m_currentOperation;

};

#endif // ANIMATIONQUEUE_H
