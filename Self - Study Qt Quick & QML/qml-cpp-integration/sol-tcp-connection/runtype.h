/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef RUNTYPE_H
#define RUNTYPE_H

#include <QDialog>

namespace Ui {
    class RunType;
}

class RunType : public QDialog
{
    Q_OBJECT

public:
    enum Type { Server, Client };
    explicit RunType(QWidget *parent = Q_NULLPTR);
    Type getRunType();
    ~RunType();

private Q_SLOTS:
    void client();
    void server();

private:
    Ui::RunType *ui;
    Type m_type;
};

#endif // RUNTYPE_H
