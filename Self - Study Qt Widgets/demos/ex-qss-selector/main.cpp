/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

int y = 400;

template<class PushButtonClass>
PushButtonClass *setup(const QString &title, QWidget *top)
{
    top->setWindowTitle(title);
    QHBoxLayout *layout = new QHBoxLayout(top);
    PushButtonClass *enabled = new PushButtonClass("Enabled");
    PushButtonClass *disabled = new PushButtonClass("Disabled");
    disabled->setEnabled(false);

    layout->addWidget(enabled);
    layout->addWidget(disabled);
    top->resize(500, 30);

    top->move(1400, y);
    y += 100;

    top->show();

    return enabled;
}

class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    MyPushButton(const QString &text)
        : QPushButton(text)
    {}
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    setup<QPushButton>("1: QPushButtons in a QDialog", new QDialog);
    setup<QPushButton>("2: QPushButtons in a QWidget", new QWidget);
    setup<MyPushButton>("3: MyPushButtons in a Dialog", new QDialog);
    QPushButton *button = setup<QPushButton>("4: QPushButtons named me", new QDialog);
    button->setObjectName("me");

    button = setup<QPushButton>("5: QPushButtons with a dynamic property", new QDialog);
    button->setProperty("dynamicProp", true);

    QStringList settings;
    app.setStyleSheet(
        "* {"
        "   border-width: 10px;"
        "   border-style: solid;"
        "}\n"
        "QPushButton {"
        "   border-left-color: green;"
        "}\n"
        "QPushButton[enabled=\"true\"] {"
        "   border-left-color: blue;"
        "}\n"
        "QDialog QPushButton[enabled=\"true\"] {"
        "   border-left-color: red;"
        "}\n"
        "QDialog QPushButton[enabled=\"false\"] {"
        "   border-left-color: yellow;"
        "}\n"
        "QDialog .QPushButton[enabled=\"true\"] {"
        "   border-left-color: black;"
        "}\n"
        "QPushButton:hover {"
        "   border-right-color: blue;"
        "}\n"
        "QPushButton:pressed {"
        "   border-right-color: yellow;"
        "}\n"
        "QPushButton#me {"
        "   border-top-color: red;"
        "}\n"
        "QDialog .QPushButton[dynamicProp=\"true\"] {"
        "   border-top-color: blue;"
        "}"
    );

    return app.exec();
}

#include "main.moc"
