/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QFileSystemModel>
#include <QtWidgets/QListView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QSplitter splitter;

    QTreeView *tree = new QTreeView(&splitter);
    QListView *list = new QListView(&splitter);

    QFileSystemModel *model = new QFileSystemModel(&app);
    model->setRootPath(QDir::root().path());

    tree->setModel(model);
    list->setModel(model);

    list->setRootIndex(model->index("."));

    splitter.show();

    return app.exec();
}
