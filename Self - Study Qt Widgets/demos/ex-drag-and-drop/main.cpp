/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
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
    StringListModel(const QStringList& list, QObject *parent = Q_NULLPTR)
        : QAbstractListModel(parent), _list(list) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE
    {
        Q_UNUSED( parent );
        return _list.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE
    {
        if (!index.isValid())
            return QVariant();

        if (index.row() < 0 || index.row() >= _list.size())
            return QVariant();

        if (role == Qt::DisplayRole)
            return _list.at(index.row());
        else
            return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            Q_ASSERT( section == 0 );
            return QString("Country");
        }
        else
            return QString("Countr %1").arg(section);
    }

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE
    {
        if (!index.isValid())
            return Qt::ItemIsEnabled
                | Qt::ItemIsDropEnabled;

        return QAbstractItemModel::flags(index)
               | Qt::ItemIsEditable
               | Qt::ItemIsDragEnabled
               | Qt::ItemIsDropEnabled;
    }

    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role = Qt::EditRole) Q_DECL_OVERRIDE
    {
        Q_UNUSED( role );

        if (index.isValid()) {
            _list.replace(index.row(), value.toString());
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    bool insertRows(int position, int rows, const QModelIndex& /*parent*/) Q_DECL_OVERRIDE
    {
        beginInsertRows(QModelIndex(), position, position+rows-1);

        for (int row = 0; row < rows; ++row) {
            _list.insert(position, "");
        }

        endInsertRows();
        return true;
    }

    bool removeRows(int position, int rows, const QModelIndex& /*parent*/) Q_DECL_OVERRIDE
    {
        beginRemoveRows(QModelIndex(), position, position+rows-1);

        for (int row = 0; row < rows; ++row) {
            _list.removeAt(position);
        }

        endRemoveRows();
        return true;
    }

    QStringList mimeTypes() const Q_DECL_OVERRIDE
    {
        return QAbstractListModel::mimeTypes() << "text/plain";
    }

    QMimeData *mimeData(const QModelIndexList& indexes) const Q_DECL_OVERRIDE
    {
        QStringList list;
        for (const QModelIndex &index : indexes)
            list << data(index).toString();

        QMimeData *mimeData = QAbstractListModel::mimeData(indexes);
        mimeData->setText(list.join(", "));
        return mimeData;
    }

    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) Q_DECL_OVERRIDE
    {
        if  (data->hasText()) {
            if (parent.isValid()) {
                // drop on an item
                setData(parent, data->text());
            }
            else {
                // drop outside items
                insertRows(rowCount(), 1, QModelIndex());
                setData(index(rowCount()-1, 0, QModelIndex() ), data->text());
            }
            return true;
        }
        else
            return QAbstractListModel::dropMimeData(data, action, row, column, parent);
    }

private:
    QStringList _list;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList countries;
    countries << "Denmark" << "Norway" << "Sweeden" << "USA" << "Poland";
    StringListModel model(countries);

    QListView list;
    list.setModel(&model);
    list.setWindowTitle("QListView");
    list.setDragEnabled(true);
    list.setAcceptDrops(true);
    list.show();

    QTreeView tree;
    tree.setModel(&model);
    tree.setWindowTitle("QTreeView");
    tree.setDragEnabled(true);
    tree.setAcceptDrops(true);
    tree.show();

    QTableView table;
    table.setModel(&model);
    table.setDragEnabled(true);
    table.setAcceptDrops(true);
    table.setWindowTitle("QTableView");
    table.show();

    return app.exec();
}

#include "main.moc"
