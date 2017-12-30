#include <QPainter>
#include "puzzle.h"

#include <QDebug>

Puzzle::Puzzle(QWidget *parent)
    : QWidget(parent),
      m_count(0)
{
    m_image = QPixmap(":/images/lady.png").scaled(rect().width(), rect().height());
    m_question = QPixmap(":/images/question.png").scaled(m_image.size());

    int imageWidth(m_image.width());
    int imageHeight(m_image.height());

    QPolygon polygonPoints;

    polygonPoints
            << QPoint(0, 0)
            << QPoint(imageWidth * 0.3, 0)
            << QPoint(imageWidth * 0.5, imageHeight * 0.3)
            << QPoint(imageWidth * 0.6, imageHeight * 0.4)
            << QPoint(imageWidth * 0.4, imageHeight * 0.6)
            << QPoint(imageWidth * 0.2, imageHeight * 0.8 )
            << QPoint(0, imageHeight * 0.1);

    m_regions
        << QRegion(QRect(QPoint(imageWidth * 0.7, imageHeight * 0.6), QPoint(imageWidth * 0.9, imageHeight * 0.8)), QRegion::Ellipse)
        << QRect( QPoint(imageWidth * 0.2, imageHeight * 0.7), QPoint(imageWidth * 0.5, imageHeight))
        << polygonPoints
        << QRect(QPoint(imageWidth * 0.7, 0), QPoint(imageWidth, imageHeight * 0.3))
        << QRect(0, 0, m_image.width(), m_image.height());

    setFixedSize(m_image.size());
}

void Puzzle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_question);
    QRegion region;
    for (int i = 0; i < m_count; ++i)
        region += m_regions[i];
    painter.setClipRegion(region);
    painter.drawPixmap(0, 0, m_image);
}

void Puzzle::showNext()
{
    m_count = (m_count + 1) % (m_regions.size()+1);
    update();
}

