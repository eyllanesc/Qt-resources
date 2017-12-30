/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStateMachine>
#include <QFinalState>

// #define GROUPING

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setFixedSize(200, 200);
    QVBoxLayout *layout = new QVBoxLayout;
    window.setLayout(layout);
    QPushButton *button = new QPushButton("Switch to state 2");
    layout->addWidget(button);
#ifdef GROUPING
    QPushButton *quitButton = new QPushButton("Quit");
    layout->addWidget(quitButton);
#endif

    QStateMachine *machine = new QStateMachine(&window);
#ifdef GROUPING
    QState *rootState = new QState();
    QState *s1 = new QState(rootState);
    QState *s2 = new QState(rootState);
    QState *s3 = new QState(rootState);
    QFinalState *finalState = new QFinalState(); // Final state is top-level
#else
    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();
#endif

    s1->addTransition(button, &QPushButton::clicked, s2);
    s2->addTransition(button, &QPushButton::clicked, s3);
    s3->addTransition(button, &QPushButton::clicked, s1);

    s1->assignProperty(button, "text", "Switch to state 2");
    s2->assignProperty(button, "text", "Switch to state 3");
    s3->assignProperty(button, "text", "Switch to state 1");

#ifdef GROUPING
    rootState->addTransition(quitButton, &QPushButton::clicked, finalState);
QObject::connect(machine, &QStateMachine::finished, qApp, &QApplication::quit);

    machine->addState(rootState);
    machine->addState(finalState);
    rootState->setInitialState(s1);
    machine->setInitialState(rootState);
#else
    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->setInitialState(s1);
#endif
    machine->start();

    window.show();
    return a.exec();
}


