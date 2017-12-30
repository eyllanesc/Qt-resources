/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "contactform.h"

ContactForm::ContactForm(QWidget *parent)
    : QWidget(parent)
{
    createContactGroup();
    createDetailsGroup();

    QCheckBox *showDetails = new QCheckBox("Show Details");
    connect(showDetails, &QCheckBox::toggled, m_detailsGroup, &ContactForm::setVisible);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(m_contactGroup);
    layout->addWidget(showDetails);
    layout->addWidget(m_detailsGroup);
    setLayout(layout);

    m_detailsGroup->hide();
}

void ContactForm::createContactGroup()
{
    QGroupBox *box = new QGroupBox("Contact");

    QLabel *picture = new QLabel("Picture");
    picture->setFrameStyle(QFrame::StyledPanel);
    picture->setFixedSize(128, 128);
    picture->setAlignment(Qt::AlignCenter);

    QHBoxLayout *outer = new QHBoxLayout;
    {
        QGridLayout *grid = new QGridLayout;
        grid->addWidget(new QLabel("Firstname"), 0, 0, 1, 2);
        grid->addWidget(new QLabel("Lastname"),  0, 2);
        grid->addWidget(new QLineEdit,           1, 0, 1, 2);
        grid->addWidget(new QLineEdit,           1, 2);
        grid->addWidget(new QLabel("Zip Code"),  2, 0, 1, 2);
        grid->addWidget(new QLabel("City"),      2, 2);
        grid->addWidget(new QLineEdit,           3, 0, 1, 1);
        // form->setColumnMinimumWidth(1, 32);
        grid->addWidget(new QLineEdit, 3, 2);
        outer->addLayout(grid);
    }

    outer->addWidget(picture);
    box->setLayout(outer);

    m_contactGroup = box;
}

void ContactForm::createDetailsGroup()
{
    QGroupBox *box = new QGroupBox("Details");
    QVBoxLayout *layout = new QVBoxLayout(box);
    layout->addWidget(new QTextEdit);
    m_detailsGroup = box;
}
