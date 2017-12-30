/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QtWidgets/QDialog>

namespace Ui {
    class OrderForm;
}

class OrderForm : public QDialog
{
    Q_OBJECT

public:
    OrderForm(QWidget *parent = Q_NULLPTR);
    ~OrderForm();

private Q_SLOTS:
    void updateTotal();

private:
    Ui::OrderForm *ui;
};

#endif // ORDERFORM_H
