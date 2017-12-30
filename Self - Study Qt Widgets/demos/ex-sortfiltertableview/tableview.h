/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TableView_H
#define TableView_H

#include <QtWidgets>

class TableView : public QWidget
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = Q_NULLPTR);

    void setModel(QAbstractItemModel *model);

private Q_SLOTS:
    void setFilterColumn(int);

private:
    QSortFilterProxyModel *m_proxy;
    QGridLayout *m_layout;
    QTableView *m_tableView;
    QLabel *m_label;
    QLineEdit *m_lineEdit;
};


#endif
