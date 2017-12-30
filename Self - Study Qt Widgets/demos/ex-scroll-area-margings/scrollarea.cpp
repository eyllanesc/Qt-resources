/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QScrollBar>

#include "scrollarea.h"

ScrollArea::ScrollArea(QWidget *parent) :
    QScrollArea(parent)
{
    QWidget *contents = new QWidget();
    contents->setMinimumSize(100, 20*10);
    setWidget(contents);

    for (m_mNumCheckboxes = 0; m_mNumCheckboxes < 10; m_mNumCheckboxes++) {
        QCheckBox *b = new QCheckBox(QString("box #%1").arg(m_mNumCheckboxes), contents);
        b->move( 0, m_mNumCheckboxes*20);
    }

    m_more1 = new QPushButton("Show renders", this);
    m_more2 = new QPushButton("More", this);

    connect(m_more1, &QPushButton::clicked, this, &ScrollArea::showRenders);
    connect(m_more2, &QPushButton::clicked, this, &ScrollArea::slotMore);

    setViewportMargins(0, m_more1->sizeHint().height(), 0, m_more2->sizeHint().height());
}

ScrollArea::~ScrollArea()
{
    if (m_label1)
        delete m_label1;
    if (m_label2)
        delete m_label2;
}

void ScrollArea::slotMore()
{
    QCheckBox *b = new QCheckBox(QString("box #%1").arg(m_mNumCheckboxes), widget());
    b->move(0, m_mNumCheckboxes*20);
    b->show();
    m_mNumCheckboxes++;
    widget()->setMinimumSize(100, 20*m_mNumCheckboxes);

    verticalScrollBar()->setValue(20*m_mNumCheckboxes);
}

void ScrollArea::showRenders()
{
    QPixmap widgetPixmap(size());
    render(&widgetPixmap);

    QPixmap viewPortPixmap(widget()->size());
    widget()->render(&viewPortPixmap);

    m_label1 = new QLabel;
    m_label2 = new QLabel;
    m_label1->setPixmap(widgetPixmap);
    m_label2->setPixmap(viewPortPixmap);

    m_label1->show();
    m_label2->show();

}

void ScrollArea::resizeEvent(QResizeEvent *event)
{
    m_more1->move(0, 0);
    m_more2->move(0, 2+m_more1->sizeHint().height()+ viewport()->size().height());
    QScrollArea::resizeEvent(event);
}
