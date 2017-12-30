/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

class DemoWidget : public QWidget
{
public:
    DemoWidget(QWidget *parent = 0)
        : QWidget(parent)
    {}

    void addButtons(QLayout *layout)
    {
        layout->addWidget(new QPushButton("One"));
        layout->addWidget(new QPushButton("Two"));
        layout->addWidget(new QPushButton("Three"));
        layout->addWidget(new QPushButton("Four"));
        layout->addWidget(new QPushButton("Five"));
    }

    void createHBoxLayout()
    {
        QHBoxLayout *layout = new QHBoxLayout;
        addButtons(layout);
        setLayout(layout);
    }

    void createVBoxLayout()
    {
        QVBoxLayout *layout = new QVBoxLayout;
        addButtons(layout);
        setLayout(layout);
    }

    void createGridLayout()
    {
        QGridLayout *layout = new QGridLayout;
        layout->addWidget(new QPushButton("One"), 0, 0);
        layout->addWidget(new QPushButton("Two"), 0, 1);
        layout->addWidget(new QPushButton("Three"), 1, 0, 1, 2);
        setLayout(layout);
    }

    void createFormLayout()
    {
        QFormLayout *layout = new QFormLayout;
        layout->addRow("One", new QPushButton("One"));
        layout->addRow("Two", new QPushButton("Two"));
        layout->addRow("Three", new QPushButton("Three"));
        setLayout(layout);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DemoWidget row, col, grid, form;
    row.createHBoxLayout();
    col.createVBoxLayout();
    grid.createGridLayout();
    form.createFormLayout();
    row.show();
    col.show();
    grid.show();
    form.show();
    return app.exec();
}
