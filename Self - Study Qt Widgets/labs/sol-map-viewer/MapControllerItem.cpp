/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MapControllerItem.h"

#include <QtWidgets/QGraphicsLinearLayout>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QPushButton>

MapControllerItem::MapControllerItem(QGraphicsItem *p, Qt::WindowFlags flags)
  : QGraphicsWidget(p, flags), m_zoomSlider(0)
{
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);
    setLayout(layout);

    QPushButton *zoomInButton = new QPushButton(QLatin1String("+"));
    zoomInButton->setFixedWidth(50);
    zoomInButton->setAttribute( Qt::WA_NoSystemBackground);
    QGraphicsProxyWidget* zoomInButtonProxy = new QGraphicsProxyWidget;
    zoomInButtonProxy->setWidget( zoomInButton);
    layout->addItem(zoomInButtonProxy);

    m_zoomSlider = new QSlider(Qt::Vertical);
    m_zoomSlider->setAttribute(Qt::WA_NoSystemBackground);
    m_zoomSlider->setRange(10, 500);
    m_zoomSlider->setValue(100);
    m_zoomSlider->setSingleStep(20);
    m_zoomSlider->setPageStep(100);
    m_zoomSlider->setTickPosition(QSlider::TicksBothSides);
    QGraphicsProxyWidget *m_zoomSliderProxy = new QGraphicsProxyWidget(this);
    m_zoomSliderProxy->setWidget(m_zoomSlider);
    layout->addItem(m_zoomSliderProxy);

    QPushButton* zoomOutButton = new QPushButton( QLatin1String("-") );
    zoomOutButton->setFixedWidth(50);
    zoomOutButton->setAttribute( Qt::WA_NoSystemBackground );
    QGraphicsProxyWidget* zoomOutButtonProxy = new QGraphicsProxyWidget;
    zoomOutButtonProxy->setWidget(zoomOutButton);
    layout->addItem( zoomOutButtonProxy );

    connect(m_zoomSlider, &QSlider::valueChanged, this, &MapControllerItem::zoomChanged);
    connect(zoomInButton, &QPushButton::clicked, this, &MapControllerItem::zoomIn);
    connect(zoomOutButton, &QPushButton::clicked, this, &MapControllerItem::zoomOut);
}

MapControllerItem::~MapControllerItem()
{
}

void MapControllerItem::zoomIn()
{
    m_zoomSlider->setValue(m_zoomSlider->value() + m_zoomSlider->singleStep());
}

void MapControllerItem::zoomOut()
{
    m_zoomSlider->setValue(m_zoomSlider->value() - m_zoomSlider->singleStep());
}
