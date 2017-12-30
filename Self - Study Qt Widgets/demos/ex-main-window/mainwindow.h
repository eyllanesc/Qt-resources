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

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public: // constructor
    MainWindow(QWidget *parent = Q_NULLPTR);

public: // setup functions
    void setupActions();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    void setupDockWindow();

private slots:
    void onFileNew();
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
    void onHelpAbout();

private: // data member
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_helpMenu;
    QToolBar *m_toolBar;
    QAction *m_fileNew;
    QAction *m_fileOpen;
    QAction *m_fileSave;
    QAction *m_fileSaveAs;
    QAction *m_fileExit;
    QAction *m_editUndo;
    QAction *m_editRedo;
    QAction *m_editCut;
    QAction *m_editCopy;
    QAction *m_editPaste;
    QAction *m_helpAbout;
    QAction *m_helpAboutQt;
};

#endif // MAINWINDOW_H
