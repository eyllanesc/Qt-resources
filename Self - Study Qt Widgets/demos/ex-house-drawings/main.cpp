/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class Test : public QWidget {

public:
    Test(QWidget *parent = Q_NULLPTR)
        : QWidget(parent)
    {
    }

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE
    {
        QPainter painter(this);

        // Blue House
        {
            QPainterPath house;
            house.addRect(QRect(QPoint(300, 250), QPoint(400, 350)));
            house.addRect(QRect(QPoint(340, 350), QPoint(360, 300)));
            house.addRect(QRect(QPoint(310, 270), QPoint(330, 290)));
            house.addRect(QRect(QPoint(390, 270), QPoint(370, 290)));

            painter.setBrush(Qt::blue);
            painter.fillPath(house, painter.brush());


            painter.setBrush(Qt::yellow);
            QPainterPath roof;
            roof.moveTo(300, 250);
            roof.lineTo(350, 150);
            roof.lineTo(400, 250);
            roof.closeSubpath();
            painter.drawPath(roof);
        }

        // Green houses
        {
            QPainterPath house;
            house.addRect(QRect(QPoint(340, 350), QPoint(360, 300)));
            house.addRect(QRect(QPoint(310, 270), QPoint(330, 290)));
            house.addRect(QRect(QPoint(390, 270), QPoint(370, 290)));
            house.moveTo(300, 250);
            house.lineTo(300, 350);
            house.lineTo(400, 350);
            house.lineTo(400, 250);
            house.quadTo(QPoint(350, 150), QPoint(300, 250));

            painter.setBrush(Qt::green);
            for (int i = -2; i <= 2; ++i) {
                if (i != 0) {
                    painter.save();
                    painter.translate(i * 120, 0);
                    if (abs(i) == 1)
                        painter.drawPath(house);
                    else
                        painter.strokePath(house, painter.pen());

                    painter.restore();
                }
            }
        }

        // Text
        QPainterPath textPath;
        QFont font("helvetica", 50);

        painter.setFont( font );
        font.setStyleStrategy(QFont::ForceOutline);
        textPath.addText(50, 80, font, QString( "The Global Village"));

        int width = QFontMetrics(font).width( "The Global Village");
        QLinearGradient gradient(50, 100, width+100, 100);
        gradient.setColorAt(0, Qt::blue);
        gradient.setColorAt(0.5, Qt::green);
        gradient.setColorAt(1, Qt::yellow);
        painter.setBrush(gradient);
        painter.drawPath(textPath);

        // Line under the Text
        QPainterPath underLine;
        underLine.moveTo(50,100);
        underLine.quadTo(width/4+50, 120, width/2+50, 100);
        underLine.quadTo(3*width/4+50, 80, width+50, 100);
        painter.setBrush(gradient); // It must be a bug that I need to set this
        painter.setPen(Qt::NoPen);
        painter.drawPath(underLine);

    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Test *test = new Test;
    test->resize(700, 350);
    test->show();

    return app.exec();
}
