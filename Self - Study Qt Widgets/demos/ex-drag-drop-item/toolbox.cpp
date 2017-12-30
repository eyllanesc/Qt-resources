/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QListWidget>
#include <QtGui/QDrag>
#include <QtCore/QMimeData>
#include <QtWidgets/QGraphicsPolygonItem>
#include <QtWidgets/QGraphicsEllipseItem>
#include <QtWidgets/QGraphicsTextItem>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtWidgets/QVBoxLayout>

#include "toolbox.h"
#include "diagramitem.h"

class ToolListWidgetItem : public QListWidgetItem {
public:
    ToolListWidgetItem(int type, const QString &name);

    QVariant data(int role) const Q_DECL_OVERRIDE;
    int toolType() const { return m_type; }

private:
    void init();

    int m_type;
    QString m_name;
};

ToolListWidgetItem::ToolListWidgetItem(int type, const QString& name)
    : QListWidgetItem(name),
    m_type(type)
{
    init();
}

void ToolListWidgetItem::init()
{
    QGraphicsItem* item = DiagramItem::createItem(m_type);
    QStyleOptionGraphicsItem opt;
    QPixmap pix(111, 111);
    pix.fill(Qt::transparent);
    QPainter p(&pix);
    p.setRenderHint(QPainter::Antialiasing);
    p.translate(55, 55);
    item->paint(&p, &opt, 0);
    p.end();
    setIcon(pix);
    delete item;
}

QVariant ToolListWidgetItem::data(int role) const
{
    return QListWidgetItem::data(role);
}


class ToolListWidget : public QListWidget {
public:
    explicit ToolListWidget(QWidget* parent = Q_NULLPTR)
        : QListWidget(parent)
    {
        setSelectionMode(QAbstractItemView::SingleSelection);
        setViewMode(QListView::IconMode);
    }

protected:
    void startDrag(Qt::DropActions supportedActions) Q_DECL_OVERRIDE
    {
        QList<QListWidgetItem *> items = selectedItems();
        if (items.size()>0) {
            QDrag* drag = new QDrag( this );
            QMimeData *mimeData = new QMimeData;
            ToolListWidgetItem* item = static_cast<ToolListWidgetItem*>( items[0] );
            QGraphicsItem* gitem = DiagramItem::createItem( item->toolType() );
            mimeData->setData( "application/x-qgraphicsitem-ptr",
                               QByteArray::number( ( qulonglong )gitem ) );
            drag->setMimeData( mimeData );
            QPixmap pix = item->icon().pixmap( 111,111 );
            drag->setPixmap( pix );
            drag->setHotSpot( pix.rect().center() );
            if (drag->exec(supportedActions) == Qt::IgnoreAction) {
                // Drag cancelled, we need to clean up the item
                delete gitem;
            }
        }
    }
};

class ColorlistWidget : public QListWidget {
public:
    explicit ColorlistWidget( QWidget *parent = Q_NULLPTR )
        : QListWidget(parent)
    {
        setSelectionMode(QAbstractItemView::SingleSelection);
        setViewMode(QListView::IconMode);
    }

protected:
    void startDrag(Qt::DropActions supportedActions) Q_DECL_OVERRIDE
    {
        QList<QListWidgetItem *> items = selectedItems();
        if (items.size()>0) {
            QDrag* drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;
            QColor color(items[0]->text());
            mimeData->setColorData(color);
            QPixmap pix(20, 20);
            pix.fill(color);
            drag->setPixmap(pix);
            drag->setMimeData(mimeData);
            drag->exec(supportedActions);
        }
    }

};

ToolBox::ToolBox(QWidget* parent)
    : QDockWidget(tr( "Toolbox" ), parent)
{
    QListWidget *tools = new ToolListWidget;
    tools->setDragDropMode(QAbstractItemView::DragOnly);
    tools->addItem(new ToolListWidgetItem( DiagramItem::TYPE_BOX, tr("Box")));
    tools->addItem(new ToolListWidgetItem( DiagramItem::TYPE_TRIANGLE, tr("Triangle")));
    tools->addItem(new ToolListWidgetItem( DiagramItem::TYPE_PENTAGON, tr("Pentagon")));
    tools->addItem(new ToolListWidgetItem( DiagramItem::TYPE_ELLIPSE, tr( "Ellipse")));

    QListWidget *colors = new ColorlistWidget;
    colors->setDragDropMode(QAbstractItemView::DragOnly);
    colors->addItem(tr("Red"));
    colors->addItem(tr("Green"));
    colors->addItem(tr("Blue"));

    QWidget *top = new QWidget;
    QVBoxLayout *l = new QVBoxLayout(top);
    l->addWidget(tools);
    l->addWidget(colors);

    setWidget(top);
}
