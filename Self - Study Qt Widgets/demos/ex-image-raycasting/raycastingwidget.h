/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef RAYCASTINGWIDGET_H
#define RAYCASTINGWIDGET_H

#include <QWidget>
#include <QTime>
#include <QBasicTimer>
#include <math.h>

#ifndef M_PI
static const double M_PI = 3.14159265358979323846;
#endif

static const int WORLD_SIZE = 8;
static const int world_map[WORLD_SIZE][WORLD_SIZE] = {
    { 1, 1, 1, 1, 6, 1, 1, 1 },
    { 1, 0, 0, 1, 0, 0, 0, 7 },
    { 1, 1, 0, 1, 0, 1, 1, 1 },
    { 6, 0, 0, 0, 0, 0, 0, 3 },
    { 1, 8, 8, 0, 8, 0, 8, 1 },
    { 2, 2, 0, 0, 8, 8, 7, 1 },
    { 3, 0, 0, 0, 0, 0, 0, 5 },
    { 2, 2, 2, 2, 7, 4, 4, 4 },
};

static const int TEXTURE_SIZE = 64;
static const int TEXTURE_BLOCK = TEXTURE_SIZE * TEXTURE_SIZE;

class RayCastingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RayCastingWidget(QWidget *parent = Q_NULLPTR);

protected:
    void updatePlayer();
    void showFps();
    void render();

    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;

private:
    QTime watch;
    QBasicTimer ticker;
    QImage buffer;
    qreal angle;
    QPointF playerPos;
    qreal angleDelta;
    qreal moveDelta;
    QImage textureImg;
    int textureCount;
    bool touchDevice;
    QRect trackPad;
    QPoint centerPad;
    QSize bufferSize;
};

#endif // RAYCASTINGWIDGET_H
