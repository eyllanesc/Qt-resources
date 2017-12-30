/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLayout>
#include "filechooser.h"

FileChooser::FileChooser(QWidget *parent)
    : QWidget(parent),
      m_mode(File)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(4);

    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    connect(m_lineEdit, &QLineEdit::textChanged, this, &FileChooser::fileNameChanged);
    m_button = new QPushButton("...", this);
    layout->addWidget(m_button);

    connect(m_button, &QPushButton::clicked, this, &FileChooser::chooseFile);

    setFocusProxy(m_lineEdit);
}

void FileChooser::setMode(Mode mode)
{
    m_mode = mode;
}

FileChooser::Mode FileChooser::mode() const
{
    return m_mode;
}

void FileChooser::setFileName(const QString &fileName)
{
    m_lineEdit->setText(fileName);
}

QString FileChooser::fileName() const
{
    return m_lineEdit->text();
}

void FileChooser::chooseFile()
{
    QString fileName;
    if (mode() == File) {
        fileName = QFileDialog::getOpenFileName(this, QString(), m_lineEdit->text());
    } else {
        fileName = QFileDialog::getExistingDirectory(this, QString(), m_lineEdit->text());
    }

    if ( !fileName.isEmpty() ) {
        m_lineEdit->setText(fileName);
        emit fileNameChanged(fileName);
    }
}
