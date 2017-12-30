/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QEventLoop>
#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent) :
    QPushButton(parent),
    m_modal(false),
    m_eventLoop(Q_NULLPTR)
{
}

CustomButton::~CustomButton()
{
    if (m_modal && m_eventLoop)
        m_eventLoop->quit();
}

void CustomButton::showModal()
{
    setAttribute(Qt::WA_ShowModal, true);
    setText("Modal Button");
    m_modal = true;
    show();
    QEventLoop eventLoop;
    m_eventLoop = &eventLoop;
    m_eventLoop->exec();
}

void CustomButton::showNonModal()
{
    setText("Non-Modal Button");
    show();
}
