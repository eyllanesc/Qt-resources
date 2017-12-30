/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtCore>

bool operator<(const QPoint& p1, const QPoint& p2)
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

int main(int, char *[])
{

}
