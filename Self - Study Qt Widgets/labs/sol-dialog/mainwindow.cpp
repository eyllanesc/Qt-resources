/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "valuedialog.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      m_valueDialog(0)
{
    setWindowTitle("Main Window");
    m_slider = new QSlider(Qt::Horizontal, this);
    m_message = new QLabel(this);

    QPushButton *modal = new QPushButton("Modal", this);
    connect(modal, &QPushButton::clicked, this, &MainWindow::onModal);
    QPushButton *modeless = new QPushButton("Modeless", this);
    connect(modeless, &QPushButton::clicked, this, &MainWindow::onModeless);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_slider);
    layout->addWidget(m_message);

    QHBoxLayout *inner = new QHBoxLayout;
    inner->addWidget(modal);
    inner->addWidget(modeless);
    layout->addLayout(inner);

    setLayout(layout);
}

void MainWindow::onModal()
{
    ValueDialog dialog(this);
    dialog.setWindowTitle("Modal Dialog");
    dialog.setValue(m_slider->value());
    connect(&dialog, &ValueDialog::valueChanged, m_slider, &QSlider::setValue);
    connect(m_slider, &QSlider::valueChanged, &dialog, &ValueDialog::setValue);
    dialog.exec();
    m_message->setText("exec returns after user closes dialog");
}

void MainWindow::onModeless()
{
    if(!m_valueDialog) {
        m_valueDialog = new ValueDialog(this);
        m_valueDialog->setWindowTitle("Modeless Dialog");
        m_valueDialog->setValue(m_slider->value());
        connect(m_valueDialog, &ValueDialog::valueChanged, m_slider, &QSlider::setValue);
        connect(m_slider, &QSlider::valueChanged, m_valueDialog, &ValueDialog::setValue);
    }
    m_valueDialog->show();
    m_valueDialog->raise();
    m_valueDialog->activateWindow();
    m_message->setText("show returns immediately");
}
