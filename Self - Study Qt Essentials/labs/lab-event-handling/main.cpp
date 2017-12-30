/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include "quotebutton.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget top;
    top.setWindowTitle("Quotes from Office Space");

    QuoteButton *button = new QuoteButton("Quote", &top);
    QTextEdit *edit = new QTextEdit(&top);
    QObject::connect(
        button, &QuoteButton::quote,
        edit, &QTextEdit::setText
    );

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(edit);
    top.setLayout(layout);
    top.show();

    return app.exec();
}
