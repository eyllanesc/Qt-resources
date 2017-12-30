/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class TextEdit : public QTextEdit {

};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStandardItemModel *model = new QStandardItemModel(&app);
    bool canDrag(false);
    bool canDrop(false);
    for (int i=0; i<10; i++) {
        QStandardItem *item = new QStandardItem();
        canDrag = i%2 == 0;
        canDrop = i%3 == 0;
        item->setDragEnabled(canDrag);
        item->setDropEnabled(canDrop);
        item->setText(QString("Item-%1 (%2/%3)").arg(i)
                      .arg(canDrag?"DRAG":"-")
                      .arg(canDrop?"DROP":"-"));
        model->appendRow(item);
    }

    QWidget window;
    QGridLayout *layout = new QGridLayout(&window);

    QListView *listView = new QListView();
    listView->setDropIndicatorShown(true);
    listView->setDragEnabled(true);
    listView->setAcceptDrops(true);
    listView->setModel(model);

    QTableView *tableView = new QTableView();
    tableView->setDropIndicatorShown(true);
    tableView->setDragEnabled(true);
//    tableView->setAcceptDrops(true);
    tableView->setModel(model);

    QTreeView *treeView = new QTreeView();
    treeView->setDropIndicatorShown(true);
//    treeView->setDragEnabled(true);
    treeView->setAcceptDrops(true);
    treeView->setModel(model);

    layout->addWidget(new QLabel("QListView (DRAG/DROP)"), 0, 0);
    layout->addWidget(listView, 1, 0);
    layout->addWidget(new QLabel("QTableView (DRAG/-)"), 0, 1);
    layout->addWidget(tableView, 1, 1);
    layout->addWidget(new QLabel("QTreeView (-/DROP)"), 0, 2);
    layout->addWidget(treeView, 1, 2);

    qDebug() << "model supported mime types: " << model->mimeTypes();
    qDebug() << "model supported drag actions: " << model->supportedDragActions();
    qDebug() << "model supported drop actions: " << model->supportedDropActions();
    qDebug() << "\t QDropEvent::Copy = 0x0; QDropEvent::Link = 0x1, QDropEvent::Move = 0x2";

    window.show();
    return app.exec();
}
