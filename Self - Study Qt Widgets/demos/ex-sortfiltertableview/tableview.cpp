/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

#include "tableview.h"


TableView::TableView(QWidget *parent)
    : QWidget (parent)
    , m_proxy (new QSortFilterProxyModel(this))
{
    m_layout = new QGridLayout(this);

    // setup filter form { Filter: [         ] }
    m_label = new QLabel("Filter:", parent);
    m_layout->addWidget(m_label, 0, 0);

    m_lineEdit = new QLineEdit(parent);
    m_layout->addWidget(m_lineEdit, 0, 1);
    m_label->setBuddy(m_lineEdit);

    // setup table view
    m_tableView = new QTableView(this);
    m_layout->addWidget(m_tableView, 1, 0, 1, 2);

    m_tableView->setSortingEnabled( true );
    m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // setup proxy
    m_proxy->setSortCaseSensitivity(Qt::CaseInsensitive);
    m_proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // connect sorting and filtering
    connect  (m_tableView->horizontalHeader(), &QHeaderView::sectionClicked,
              this, &TableView::setFilterColumn);
    connect  (m_lineEdit, &QLineEdit::textChanged,
              m_proxy, &QSortFilterProxyModel::setFilterWildcard);

    // which column to filter
    setFilterColumn(1); // Country
}

void TableView::setModel(QAbstractItemModel *model)
{
    m_proxy->setSourceModel(model);
    m_tableView->setModel(m_proxy);
    m_tableView->resizeColumnsToContents();
    m_tableView->verticalHeader()->hide();
}

void TableView::setFilterColumn(int column)
{
    m_proxy->setFilterKeyColumn(column);
    m_lineEdit->setFocus();
    m_lineEdit->clear();
}
