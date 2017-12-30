/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_logAll(true)
{
    setWindowTitle(tr("Widget Event Example"));
    setFocusPolicy(Qt::StrongFocus);
}

bool Widget::event(QEvent *event)
{
    if(m_logAll) {
        Q_EMIT notifyEvent("event", event);
    }
    return QWidget::event(event);
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_EMIT notifyEvent("paintEvent", event);
    QWidget::paintEvent(event);
}


// input events
void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_EMIT notifyEvent("keyPressEvent", event);
    QWidget::keyPressEvent(event);
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    Q_EMIT notifyEvent("keyReleaseEvent", event);
    QWidget::keyReleaseEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT notifyEvent("mousePressEvent", event);
    QWidget::mousePressEvent(event);
    // for context menus use contextMenuEvent(...)
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_EMIT notifyEvent("mouseReleaseEvent", event);
    QWidget::mouseReleaseEvent(event);
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_EMIT notifyEvent("mouseDoubleClickEvent", event);
    QWidget::mouseDoubleClickEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{    
    Q_EMIT notifyEvent("mouseMoveEvent", event);
    QWidget::mouseMoveEvent(event);
}

// focus events
void Widget::focusInEvent(QFocusEvent *event)
{
    Q_EMIT notifyEvent("focusInEvent", event);
    QWidget::focusInEvent(event);
}

void Widget::focusOutEvent(QFocusEvent *event)
{
    Q_EMIT notifyEvent("focusOutEvent", event);
    QWidget::focusOutEvent(event);
}

// geometry events
void Widget::resizeEvent(QResizeEvent *event)
{
    Q_EMIT notifyEvent("resizeEvent", event);
    QWidget::resizeEvent(event);
}

void Widget::hideEvent(QHideEvent *event)
{
    Q_EMIT notifyEvent("hideEvent", event);
    QWidget::hideEvent(event);
}

void Widget::showEvent(QShowEvent *event)
{
    Q_EMIT notifyEvent("showEvent", event);
    QWidget::showEvent(event);
}

// other events
void Widget::closeEvent(QCloseEvent *event)
{
    Q_EMIT notifyEvent("closeEvent", event);
    QWidget::closeEvent(event);
}


void Widget::setLogAll(bool logAll)
{
    m_logAll = logAll;
}
