/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGridLayout>
#include <QPushButton>
#include "mywidget.h"
#include "blobwidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent), m_blobWidget(new BlobWidget(this))
{
    QGridLayout* layout = new QGridLayout(this);
    for (int i = 0; i < 16; ++i)  {
        QPushButton* but = new QPushButton(QString::number(i),  this);
        layout->addWidget(but,  i/4, i%4);
        connect(but, SIGNAL(clicked()), this, SLOT(selectButton()));
    }
    m_blobWidget->hide();
}

void MyWidget::selectButton()
{
    const QPushButton *selected = static_cast<const QPushButton*>(sender());
    m_blobWidget->raise();
    m_blobWidget->show();
    m_blobWidget->setGeometry(selected->geometry().adjusted(-20, -20, 20, 20 ));
}
