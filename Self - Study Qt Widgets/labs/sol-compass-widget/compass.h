/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef COMPASS_H
#define COMPASS_H

#include <QtWidgets>

class Compass : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Direction)

public:
    enum Direction { North, South, East, West };

    Compass(QWidget *parent = Q_NULLPTR);
    Compass(Direction d, QWidget *parent = Q_NULLPTR);
    Direction direction() const;
    QString directionName(Direction d) const;

public slots:
    void setDirection(Compass::Direction d);

signals:
    void directionChanged(Compass::Direction d);
    void directionChanged(const QString &name);

private:
    void init();

private Q_SLOTS:
    void buttonClicked(int id);

private:
    Direction m_direction;
    QButtonGroup *m_group;
    QMap<Direction,QString> m_directionMap;
};

#endif // COMPASS_H
