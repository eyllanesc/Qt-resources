/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QPainter>
#include <QStyle>
#include <QStyleOptionFocusRect>
#include <QStyleOptionGraphicsItem>
#include <QPalette>
#include <QApplication>
#include "coordinatesystem.h"


CoordinateSystem::CoordinateSystem( QGraphicsItem* parent )
    : QGraphicsItem( parent ),
      m_rect( -50, -50, 100, 100 ),
      m_edgePen( Qt::black, 1, Qt::DashLine ),
      m_edgeBrush( Qt::NoBrush ),
      m_axisPen( Qt::black, 2, Qt::SolidLine )
{
    setFlags(QGraphicsItem::ItemIsMovable );
}

CoordinateSystem* CoordinateSystem::copy() {

    CoordinateSystem *retval = new CoordinateSystem;

    retval->setPos(pos());
    retval->setRotation(rotation());
    retval->setScale(scale());
    retval->setTransform(transform());
    retval->setTransformOriginPoint(transformOriginPoint());
    retval->setZValue(zValue());
    retval->m_rect = m_rect;
    retval->m_edgePen = m_edgePen;
    retval->m_edgeBrush = m_edgeBrush;
    retval->m_axisPen = m_axisPen;
    retval->m_text = m_text;
    return retval;
}

void CoordinateSystem::setRect( const QRectF& r )
{
    if ( r != m_rect ) {
        prepareGeometryChange();
        m_rect = r;
    }
}

QRectF CoordinateSystem::rect() const
{
    return m_rect;
}

void CoordinateSystem::setText( const QString& txt )
{
    m_text = txt;
    update();
}

QString CoordinateSystem::text() const
{
    return m_text;
}

QRectF CoordinateSystem::boundingRect() const
{
    qreal pw = std::max( m_edgePen.width(), m_axisPen.width() )/2. + 5.;
    return m_rect.adjusted( -pw, -pw, pw, pw );
}

void CoordinateSystem::paint( QPainter* p, const QStyleOptionGraphicsItem* opt, QWidget* )
{
    p->setPen( edgePen() );
    p->setBrush( edgeBrush() );
    p->drawRect( rect() );

    const qreal arrowSize = 20.;

    p->setPen( axisPen() );
    p->drawLine( QLineF( 0, rect().top(), 0, rect().bottom() ) );
    p->drawLine( QLineF( rect().width()/arrowSize, rect().bottom()-rect().height()/arrowSize, 0, rect().bottom() ) );
    p->drawLine( QLineF( -rect().width()/arrowSize, rect().bottom()-rect().height()/arrowSize, 0, rect().bottom() ) );

    p->drawLine( QLineF( rect().left(), 0, rect().right(),0 ) );
    p->drawLine( QLineF( rect().right()-rect().width()/arrowSize, rect().height()/arrowSize, rect().right(),0 ) );
    p->drawLine( QLineF( rect().right()-rect().width()/arrowSize, -rect().height()/arrowSize, rect().right(),0 ) );

    p->drawText( rect().adjusted( 3., 3., -3., -3. ), text() );

    if ( opt->state & QStyle::State_Selected ) {
        p->setPen( QPen( Qt::blue, 1., Qt::DashLine ) );
        p->setBrush( Qt::NoBrush );
        p->drawRect( rect().adjusted( -4., -4., 4., 4. ) );
    }
}

