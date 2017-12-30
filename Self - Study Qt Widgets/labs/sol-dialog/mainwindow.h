/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class ValueDialog;

/*!
  Shows a slider, a message label and two buttons.
  Button modal, launches a modal dialog
  Button modeless, launches a modeless dialog
  The slider value changed is connected to the dialog set value.
  */
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private Q_SLOTS:
    void onModal();
    void onModeless();

private:
    QSlider *m_slider;
    ValueDialog *m_valueDialog;
    QLabel *m_message;
};

#endif // MAINWINDOW_H
