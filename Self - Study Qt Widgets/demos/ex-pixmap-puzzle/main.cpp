/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "puzzle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Puzzle *puzzle = new Puzzle;
    QPushButton *next = new QPushButton("Next");
    QObject::connect(next, &QPushButton::clicked, puzzle, &Puzzle::showNext);

    QHBoxLayout *hlay = new QHBoxLayout;
   // hlay->addStretch(1);
    hlay->addWidget(next);

    QVBoxLayout *vlay = new QVBoxLayout;
    vlay->addLayout(hlay);
    vlay->addWidget(puzzle);

    QWidget widget;
    widget.setLayout(vlay);
    widget.show();

    return app.exec();
}
