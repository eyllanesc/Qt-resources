/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "customlayout.h"

CustomLayout::CustomLayout(int spacing, QWidget *parent)
        : QLayout(parent)
{
    setSpacing(spacing);
}

CustomLayout::~CustomLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void CustomLayout::addItem(QLayoutItem *item)
{
    itemList.append(item);
}

bool CustomLayout::hasHeightForWidth() const
{
    return true;
}

int CustomLayout::heightForWidth(int width) const
{
    int height = doLayout(QRect(0, 0, width, 0));
    return height;
}

int CustomLayout::count() const
{
    return itemList.size();
}

QLayoutItem *CustomLayout::itemAt(int index) const
{
    return itemList.value(index);
}

QSize CustomLayout::minimumSize() const
{
    QSize size;
    QLayoutItem *item;
    foreach (item, itemList)
        size = size.expandedTo(item->minimumSize());

    size += QSize(2*spacing(), 2*spacing());
    return size;
}

void CustomLayout::setGeometry(const QRect &rect)
{
    doLayout(rect);
}

QSize CustomLayout::sizeHint() const
{
    return minimumSize();
}

QLayoutItem *CustomLayout::takeAt(int index)
{
     if (index >= 0 && index < itemList.size())
        return itemList.takeAt(index);
    else
        return 0;
}

int CustomLayout::doLayout(const QRect &rect) const
{
    int x = rect.x();
    int y = rect.y();
    int lineHeight = 0;

    for (QLayoutItem *item : itemList) {
        int spaceX = spacing();
        int spaceY = spacing();
        int nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > rect.right() && lineHeight > 0) {
            x = rect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }
    return y + lineHeight - rect.y();
}

