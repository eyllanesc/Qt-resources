/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    StringListModel(const QStringList& input, QObject *parent = Q_NULLPTR)
        : QAbstractListModel(parent), _input(input) {}


    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        if( parent.isValid() ) {
            return 0;
        }
        return _input.count();
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (!index.isValid()) {
            return QVariant();
        }

        if (index.row() < 0 || index.row() >= _input.size()) {
            return QVariant();
        }

        if (role == Qt::DisplayRole || role == Qt::EditRole) {
            return QVariant(_input.at(index.row()));
        }
        return QVariant();
    }
private:
    QStringList _input;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStringList input;
    input << "Denmark" << "Norway" << "Sweden" << "USA" << "Poland";
    StringListModel *model = new StringListModel(input);


    QListView *list = new QListView;
    list->setModel(model);
    list->setWindowTitle("QListView");
    list->show();

    QTreeView *tree = new QTreeView;
    tree->setModel(model);
    tree->setWindowTitle("QTreeView");
    tree->show();

    QTableView *table = new QTableView;
    table->setModel(model);
    table->setWindowTitle("QTableView");

    table->show();

    return app.exec();
}

#include "main.moc"
