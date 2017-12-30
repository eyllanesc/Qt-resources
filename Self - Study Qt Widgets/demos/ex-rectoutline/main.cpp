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
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE
    {
        QPainter p(this);
        p.setBrush(Qt::black);

        p.drawRect(QRectF(2.0, 2.0, 90.0, 90.0));

        p.setBrush(Qt::red);
        p.drawRect(QRectF(2.0, 102.0, 90.0, 90.0));

        p.setRenderHint(QPainter::Antialiasing);
        p.drawRect(QRectF(2.0, 202.0, 90.0, 90.0));
    }
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Test test;
    test.resize(150, 400);
    test.show();
    return app.exec();
}
