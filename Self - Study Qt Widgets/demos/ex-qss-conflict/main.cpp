/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDialog dialog;
    QHBoxLayout *layout = new QHBoxLayout(&dialog);
    QPushButton *button1 = new QPushButton("Test 1");
    QPushButton *button2 = new QPushButton("Test 2");
    QPushButton *button3 = new QPushButton("Test 3");
    button3->setObjectName("button");
    QPushButton *button4 = new QPushButton("Test 4");

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);

    dialog.show();

    // First lets check that we actually are capable of setting colors on each side
    // We will use green for win, and red for loose in the rest of the example.
    const char *sheet1 =
        "* {"
        "   border-width: 10px;"
        "   border-style: solid;"
        "}\n"
        "* {"
        "   border-top-color: green;"
        "}\n"
        "* {"
        "   border-bottom-color: blue;"
        "}\n"
        "* {"
        "   border-left-color: yellow;"
        "}\n"
        "* {"
        "   border-right-color: cyan;"
        "}";

    const char *sheet2 =
        "* {"
        "   border-width: 10px;"
        "   border-style: solid;"
        "}\n"

        // A type selector wins over a universal selector
        "* {"
        "   border-top-color: red;"
        "}\n"
        "QPushButton {"
        "   border-top-color: green;"
        "}\n"

        // Verify that the order does not matter
        "QPushButton {"
        "   border-bottom-color: green;"
        "}\n"
        "* {"
        "   border-bottom-color: red;"
        "}\n"

        // Two classes in a selector wins over one
        "QPushButton {"
        "   border-left-color: red;"
        "}\n"
        "QDialog QPushButton {"
        "   border-left-color: green;"
        "}\n"

        // Verify that the order does not matter
        "QDialog QPushButton {"
        "   border-right-color: green;"
        "}\n"
        "QPushButton {"
        "   border-right-color: red;"
        "}";

    const char *sheet3 =
        "* {"
        "   border-width: 10px;"
        "   border-style: solid;"
        "}\n"

        // Check that property specication wins over no specification
        "QPushButton[enabled=\"true\"] {"
        "   border-top-color: green;"
        "}\n"
        "QPushButton {"
        "   border-top-color: red;"
        "}\n"

        // Verify that the order does not matter
        "QPushButton {"
        "   border-bottom-color: red;"
        "}\n"
        "QPushButton[enabled=\"true\"] {"
        "   border-bottom-color: green;"
        "}\n"

        // Object name wins over property specification
        "QPushButton#button {"
        "   border-left-color: green;"
        "}\n"
        "QPushButton[enabled=\"true\"] {"
        "   border-left-color: red;"
        "}\n"

        // Verify that the order does not matter
        "QPushButton[enabled=\"true\"] {"
        "   border-right-color: red;"
        "}\n"
        "QPushButton#button {"
        "   border-right-color: green;"
        "}";

    const char *sheet4 =
        "* {"
        "   border-width: 10px;"
        "   border-style: solid;"
        "}\n"

        // More properties win over fewer
        "QPushButton[enabled=\"true\"][flat=\"false\"] {"
        "   border-top-color: green;"
        "}\n"
        "QPushButton[enabled=\"true\"] {"
        "   border-top-color: red;"
        "}\n"

        // Verify that the order does not matter
        "QPushButton[enabled=\"true\"] {"
        "   border-bottom-color: red;"
        "}\n"
        "QPushButton[enabled=\"true\"][flat=\"false\"] {"
        "   border-bottom-color: green;"
        "}\n"

        // Here we have two with same score, the later wins
        "QPushButton[enabled=\"true\"] {"
        "   border-left-color: red;"
        "}\n"
        "QPushButton[flat=\"false\"] {"
        "   border-left-color: green;"
        "}\n"

        // The same two lines reordered, still the later wins.
        "QPushButton[flat=\"false\"] {"
        "   border-right-color: red;"
        "}\n"
        "QPushButton[enabled=\"true\"] {"
        "   border-right-color: green;"
        "}";

    button1->setStyleSheet(sheet1);
    button2->setStyleSheet(sheet2);
    button3->setStyleSheet(sheet3);
    button4->setStyleSheet(sheet4);

    return app.exec();
}
