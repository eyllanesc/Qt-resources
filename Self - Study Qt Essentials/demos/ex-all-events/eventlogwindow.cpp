/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "eventlogwindow.h"

EventLogWindow::EventLogWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Event Logger");

    m_edit = new QTextEdit;
    m_edit->setFontFamily("Courier");
    m_edit->setReadOnly(true);

    QPushButton* clear = new QPushButton("Clear");
    connect(clear, &QPushButton::clicked, m_edit, &QTextEdit::clear);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(m_edit);
    layout->addWidget(clear);
    setLayout(layout);
}

void EventLogWindow::logEvent(const QString &message, QEvent *event)
{
    QString out;
    QDebug(&out) << message.leftJustified(24, '.') << event;
    m_edit->append(out);
}
