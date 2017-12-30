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
        layout->addWidget(one, 2);
        layout->addWidget(two, 1);
        layout->addWidget(three, 1);
    }

    // Exercise 2: Find this stretch
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QGroupBox *box = new QGroupBox("Exercise 2: Find this stretch");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(one, 1);
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
        layout->addStretch(1);
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
        layout->addStretch(1);
        layout->addWidget(two);
        layout->addStretch(1);
        layout->addWidget(three);
    }

    // Exercise 5: Make all buttons vertical expanding
    {
        QGroupBox *box = new QGroupBox("Exercise 5: Make all buttons vertical expanding");
        windowLayout->addWidget(box);

        QHBoxLayout *layout = new QHBoxLayout(box);
        layout->addWidget(
            new QLabel(
                "Make all buttons expand vertically using QSizePolicy. \n"
                "Hint use QObject::findChildren<T>()."
            )
        );
    }

    // This is how you would make the buttons take up the available space
    // vertically: by changing their size policy.
    QList<QPushButton *> buttons = window.findChildren<QPushButton *>();
    foreach (QPushButton *button, buttons) {
        // preserve horizontal policy
        QSizePolicy::Policy horizPolicy = button->sizePolicy().horizontalPolicy();
        // set vertical policy to MinimumExpanding
        button->setSizePolicy( QSizePolicy( horizPolicy, QSizePolicy::MinimumExpanding ) );
    }
    window.resize(640,480);
    window.show();

    return app.exec();
}
