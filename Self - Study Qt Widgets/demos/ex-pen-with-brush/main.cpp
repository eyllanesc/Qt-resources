/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class Test : public QWidget
{
public:
    Test(QWidget *parent = Q_NULLPTR)
        : QWidget(parent)
    {
        QFont fnt = font();
        fnt.setPixelSize(100);
        QFontMetrics fm(fnt);
        setFixedSize(fm.width("Hello World"), fm.height());
    }

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE
    {
        QPainter painter(this);
        QFont font = painter.font();
        font.setPixelSize(100);
        painter.setFont(font);
        QFontMetrics fm(font);

        QLinearGradient gradient(0, 0, fm.width("Hello World"), fm.height());
        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(0.5, Qt::green);
        gradient.setColorAt(1, Qt::blue);
        QBrush b(gradient);
        QPen pen(b, 0);
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);
        painter.drawText(0, 100, "Hello World");
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Test test;
    test.show();

    return app.exec();
}
