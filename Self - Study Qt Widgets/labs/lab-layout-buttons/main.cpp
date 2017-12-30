/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include<QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Layout Buttons");
    QVBoxLayout *windowLayout = new QVBoxLayout(&window);

    // Starting Point
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Starting Point");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
    }


    // Exercise 1: Stretch 2-1-1
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Exercise 1: Stretch 2-1-1");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
    }

    // Exercise 2: Find this stretch
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Exercise 2: Find this stretch");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
    }

    // Exercise 3: Stretch at the end
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Exercise 3: Stretch at the end");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
    }

    // Exercise 4: Stretch the middle
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Exercise 4: Stretch the middle");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
    }

    // Exercise 5: Make all buttons vertical expanding
    // Hint use findChildren
    window.resize(640, 480);
    window.show();

    return app.exec();
}
