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
    {}

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE
    {
        int w = width();
        int h = height()/3;
        QPainter painter(this);

        {
            QLinearGradient gradient(5, 5, w-10, h-10);
            gradient.setColorAt(0, Qt::red);
            gradient.setColorAt(0.5, Qt::green);
            gradient.setColorAt(1, Qt::blue);
            painter.setBrush(gradient);
            painter.drawRect(5, 5, w-10, h-10 );
        }

        {
            QRadialGradient gradient(w/2+5, h+h/2+5, w/2, w/3, h+h/3);
            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::green);
            gradient.setColorAt(1, Qt::black);
            painter.setBrush(gradient);
            painter.drawEllipse(5, h+5, w-10, h-10);
        }

        {
            QConicalGradient gradient(2*w/3, 2*h+h/3, 0);
            gradient.setColorAt(0, Qt::black);
            gradient.setColorAt(0.4, Qt::green);
            gradient.setColorAt(0.6, Qt::white);
            gradient.setColorAt(1, Qt::black);
            painter.setBrush(gradient);
            painter.drawEllipse(5, 2*h+5, w-10, h-10);
        }
    }
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Test test;
    test.resize(100, 300);
    test.show();

    return app.exec();
}
