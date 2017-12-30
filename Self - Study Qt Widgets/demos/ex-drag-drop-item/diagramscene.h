/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

/* -*-C++-*- */
#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtWidgets/QGraphicsScene>

class DiagramScene : public QGraphicsScene {
public:
    explicit DiagramScene(QObject *parent = Q_NULLPTR);
protected:
    void dragMoveEvent( QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dropEvent( QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
};

#endif /* DIAGRAMSCENE_H */

