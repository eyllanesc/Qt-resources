/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtCore/QTimeLine>

#include "pendulumitem.h"

class PendulumController : public QObject {
  Q_OBJECT
public:
  explicit PendulumController(QGraphicsItem* pendulum, QObject *parent = Q_NULLPTR) : QObject(parent),
								       m_pendulum(pendulum)
  {
    m_timeline.setFrameRange(-45,45);
    m_timeline.setCurveShape(QTimeLine::EaseInOutCurve);
    m_timeline.setDuration(1000);
    connect(&m_timeline, &QTimeLine::frameChanged,
         this, &PendulumController::slotRotateItem);
    connect(&m_timeline, &QTimeLine::finished,
         this, &PendulumController::slotRestartTimeLine);
    m_timeline.start();
  }

private Q_SLOTS:
  void slotRotateItem(int r)
  {
    m_pendulum->resetMatrix();
    m_pendulum->setRotation(r);
  }
  void slotRestartTimeLine()
  {
    m_timeline.toggleDirection();
    m_timeline.start();
  }

private:
  QTimeLine m_timeline;
  QGraphicsItem *m_pendulum;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene(-100,-20,200,200);
    PendulumItem *pendulum = new PendulumItem(0);
	scene->addItem(pendulum);    
    PendulumController controller(pendulum);
    QGraphicsView view(scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.resize(300, 180);
    view.show();

    return app.exec();
}

#include "main.moc"
