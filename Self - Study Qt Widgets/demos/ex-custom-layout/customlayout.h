/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CUSTOMLAYOUT_H
#define CUSTOMLAYOUT_H

#include <QLayout>

class CustomLayout : public QLayout
{
public:
    CustomLayout(int spacing = 0, QWidget *parent = Q_NULLPTR);
    ~CustomLayout();

    void addItem(QLayoutItem *item) Q_DECL_OVERRIDE;
    bool hasHeightForWidth() const Q_DECL_OVERRIDE;
    int heightForWidth(int width) const Q_DECL_OVERRIDE;
    int count() const Q_DECL_OVERRIDE;
    QLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;
    QSize minimumSize() const Q_DECL_OVERRIDE;
    void setGeometry(const QRect &rect) Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QLayoutItem *takeAt(int index) Q_DECL_OVERRIDE;
private:
    int doLayout(const QRect &rect) const;
    QList<QLayoutItem *> itemList;
};

#endif // CUSTOMLAYOUT_H
