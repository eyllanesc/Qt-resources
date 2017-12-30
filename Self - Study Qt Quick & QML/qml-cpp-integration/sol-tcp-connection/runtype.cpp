/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "runtype.h"
#include "ui_runtype.h"

RunType::RunType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunType)
{
    ui->setupUi(this);
    connect(ui->client, &QPushButton::clicked, this, &RunType::client);
    connect(ui->server, &QPushButton::clicked, this, &RunType::server);
}

RunType::~RunType()
{
    delete ui;
}

RunType::Type RunType::getRunType()
{
    exec();
    return m_type;
}

void RunType::client()
{
    m_type = Client;
    accept();
}

void RunType::server()
{
    m_type = Server;
    accept();
}
