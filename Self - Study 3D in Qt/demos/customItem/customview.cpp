#include "customview.h"
#include <QQmlContext>
#include <QQuickItem>

CustomView::CustomView(QQuickView *parent)
    : QQuickView(parent)
{
}

void CustomView::setObserver(QQuickItem *observer)
{
    m_observer = observer;
}

void CustomView::mousePressEvent(QMouseEvent *event)
{
    QMetaObject::invokeMethod(m_observer, "showTouchIndicator", Q_ARG(QVariant, event->pos()));
    QQuickView::mousePressEvent(event);
}



