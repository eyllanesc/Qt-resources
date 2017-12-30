/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

#include "bargraphdelegate.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTableView view;

    // create a model with 10 values (0, 10, 20, ... 90) and 3 columns
    QStandardItemModel *model = new QStandardItemModel();
    for(int i=0; i<100; i += 10) {
        QStandardItem *item1 = new QStandardItem(QString::number(i));
        item1->setData(QVariant(i), Qt::EditRole);
        QStandardItem *item2 = new QStandardItem(QString::number(i));
        item2->setData(QVariant(i), Qt::EditRole);
        QStandardItem *item3 = new QStandardItem(QString::number(i));
        item3->setData(QVariant(i), Qt::EditRole);
        QList<QStandardItem *> items;
        items << item1 << item2 << item3;
        model->appendRow(items);
    }
    view.setModel(model);

    view.setItemDelegate(new BarGraphDelegate());

    view.show();
    return app.exec();
}

