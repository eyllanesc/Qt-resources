/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Thu Sep 27 14:30:09 2012
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLineEdit *age;
    QLabel *label;
    QComboBox *style;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(283, 133);
        vboxLayout = new QVBoxLayout(Form);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        age = new QLineEdit(Form);
        age->setObjectName(QStringLiteral("age"));

        gridLayout->addWidget(age, 2, 1, 1, 2);

        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        style = new QComboBox(Form);
        style->setObjectName(QStringLiteral("style"));

        gridLayout->addWidget(style, 0, 2, 1, 1);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        name = new QLineEdit(Form);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 1, 1, 1, 2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        vboxLayout->addLayout(gridLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        hboxLayout->addWidget(pushButton);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "Choose Qt Style", 0));
        style->clear();
        style->insertItems(0, QStringList()
         << QApplication::translate("Form", "Windows", 0)
         << QApplication::translate("Form", "Motif", 0)
         << QApplication::translate("Form", "Plastique", 0)
        );
        label_2->setText(QApplication::translate("Form", "Name", 0));
        label_3->setText(QApplication::translate("Form", "Age", 0));
        pushButton->setText(QApplication::translate("Form", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
