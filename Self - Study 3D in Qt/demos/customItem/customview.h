#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QQuickView>

class CustomView : public QQuickView
{
public:
    CustomView(QQuickView *parent = 0);

    void setObserver(QQuickItem *);

protected:
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;

private:
    QQuickItem *m_observer;
};

#endif // CUSTOMVIEW_H
