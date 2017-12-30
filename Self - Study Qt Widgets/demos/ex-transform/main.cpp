/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class DrawingBoard : public QWidget
{
public:
    QSize sizeHint() const {
        return QSize(320, 490);
    }

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE
    {
        QPainter p(this);
        p.translate(20, 20);

        QColor red(Qt::red);
        QRect box(10, 10, 80, 80);
        QRect box2 = box.adjusted(10, 10, -10, -10);

        QPolygon points;
        points << QPoint(10, 10) << QPoint(30, 90) << QPoint(70, 90) << QPoint(90, 10);

        p.setRenderHint(QPainter::Antialiasing);
        p.setRenderHint(QPainter::TextAntialiasing);

        QFont font = p.font();
        font.setPixelSize(10);
        p.setFont(font);

        p.setPen(Qt::red);
        p.setBrush(Qt::yellow);


        drawBox(&p);
        p.drawLine(points[0], points[1]);
        p.translate(20, 0);
        p.drawLine(points[0], points[1]);
        p.translate(-20, 0);
        drawTitle(&p, "translate");

        nextRow(&p);
        drawBox(&p);
        p.save();
        p.setPen(red.lighter(125));
        p.drawRect(box);
        p.scale(.5, .5);
        p.setPen(red.lighter(150));
        p.drawRect(box);
        p.scale(2, 2);
        p.restore();
        drawCoord(&p, QPoint(0,0));
        drawTitle(&p, "scale");

        nextColumn(&p);
        drawBox(&p);
        p.save();
        p.drawRect(box2);
        p.translate(box2.center());
        p.setPen(QPen(red.lighter(125), 1, Qt::DashLine));
        p.setBrush(Qt::NoBrush);
        p.drawRect(box2);
        p.scale(.5, .5);
        p.setPen(QPen(red.lighter(150), 1, Qt::DashLine));
        p.drawRect(box2);
        p.translate(-box2.center());
        p.setPen(red);
        p.drawRect(box2);
        p.restore();
        drawCoord(&p, box2.center());
        drawTitle(&p, "scale center");


        nextRow(&p);
        drawBox(&p);
        p.save();
        p.drawRect(box2);
        p.rotate(15);
        p.drawRect(box2);
        p.restore();
        drawCoord(&p, QPoint(0, 0));
        drawTitle(&p, "rotate");

        nextColumn(&p);
        drawBox(&p);
        p.save();
        p.drawRect(box2);
        p.translate(box2.center());
        p.rotate(15);
        p.translate(-box2.center());
        p.drawRect(box2);
        p.restore();
        drawCoord(&p, box2.center());
        drawTitle(&p, "rotate center");

    }

    void drawTitle(QPainter *p, const QString &text)
    {
        p->save();
        p->setPen(Qt::blue);
        p->drawText(QRect(0, 100, 100, 50), text, QTextOption(Qt::AlignCenter));
        p->restore();
    }

    void nextColumn(QPainter *p) {
        p->translate(100, 0);
    }

    void nextRow(QPainter *p) {
        p->translate(-p->transform().dx() + 20, 150);
    }

    void drawBox(QPainter *p)
    {
        p->save();
        p->setPen(QColor(0, 0, 255, 64));
        p->setBrush(Qt::NoBrush);
        p->drawRect(0, 0, 100, 100);
        p->restore();
    }

    void drawCoord(QPainter *p, QPoint c)
    {
        p->save();
        p->setPen(Qt::DashLine);
        p->drawLine(0, c.y(), 100, c.y());
        p->drawLine(c.x(), 0, c.x(), 100);
        p->restore();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DrawingBoard board;
    board.show();
    return app.exec();
}
