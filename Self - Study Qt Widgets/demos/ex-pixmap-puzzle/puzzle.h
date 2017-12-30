/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <QWidget>
#include <QPixmap>
#include <QRegion>
#include <QList>

QT_FORWARD_DECLARE_CLASS(QMouseEvent)
QT_FORWARD_DECLARE_CLASS(QPaintEvent)

class Puzzle :public QWidget
{
    Q_OBJECT

public:
    Puzzle(QWidget *parent = Q_NULLPTR);

public Q_SLOTS:
    void showNext();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    QPixmap m_image;
    QPixmap m_question;
    QList<QRegion> m_regions;
    int m_count;
};

#endif /* PUZZLE_H */

