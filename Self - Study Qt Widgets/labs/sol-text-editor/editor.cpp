/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QLabel>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtCore/QCoreApplication>

#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include "editor.h"

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
{
    // -------------------------------------------------- Actions

    // Open
    QAction *fileOpenAction = new QAction(this);
    fileOpenAction->setText("&Open");
    fileOpenAction->setToolTip("Open a file for editing");
    fileOpenAction->setIcon(QIcon(QPixmap("fileopen.png")));
    connect(fileOpenAction, &QAction::triggered, this, &Editor::slotFileOpen);

    // Save
    m_fileSave = new QAction(this);
    m_fileSave->setText("&Save");
    m_fileSave->setToolTip("Save current file");
    m_fileSave->setIcon(QIcon(QPixmap("filesave.png")));
    connect(m_fileSave, &QAction::triggered, this, &Editor::slotFileSave);

    // Print
    m_filePrint = new QAction(this);
    m_filePrint->setText("&Print");
    m_filePrint->setToolTip("Print current file");
    m_filePrint->setIcon(QIcon(QPixmap("fileprint.png")));
    connect(m_filePrint, &QAction::triggered, this, &Editor::slotFilePrint);

    // Quit
    QAction *quitAction = new QAction(this);
    quitAction->setText("&Quit");
    quitAction->setToolTip("Quit the text editor");
    connect(quitAction, &QAction::triggered, this, &Editor::slotQuit);

    // About
    QAction *aboutAction = new QAction(this);
    aboutAction->setText("About");
    aboutAction->setToolTip("About this application");
    connect(aboutAction, &QAction::triggered, this, &Editor::slotAbout);

    // About Qt
    QAction *aboutQtAction = new QAction(this);
    aboutQtAction->setText("About Qt");
    aboutQtAction->setToolTip("About the Qt framework");
    connect(aboutQtAction, &QAction::triggered, this, &Editor::slotAboutQt);

    // -------------------------------------------------- Menubar
    QMenu *fileMenu = new QMenu(QString("&File"), menuBar());
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(m_fileSave);
    fileMenu->addAction(m_filePrint);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    QMenu *helpMenu = new QMenu("&Help", menuBar());
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    // -------------------------------------------------- Toolbar
    QToolBar *toolbar = new QToolBar("Main Toolbar", this);
    addToolBar(toolbar);

    toolbar->addAction(fileOpenAction);
    toolbar->addAction(m_fileSave);
    toolbar->addAction(m_filePrint);


    // -------------------------------------------------- Statusbar, Editor
    m_fileLabel = new QLabel(statusBar());
    statusBar()->addPermanentWidget(m_fileLabel, 0);

    // Set application icon
    setWindowIcon(QPixmap("editor.png"));

    // The editor widget:
    m_edit = new QTextEdit(this);
    m_edit->setFocus();
    m_edit->setWordWrapMode(QTextOption::WordWrap);
    m_edit->document()->setModified(false);
    setCentralWidget(m_edit);

    connect(m_edit->document(), &QTextDocument::contentsChanged,
             this, &Editor::slotTextChanged);
    slotTextChanged();
}

void Editor::closeEvent(QCloseEvent *event)
{
    event->setAccepted(false); // In case we cancel the closing, reject the event.
    slotQuit();
}

void Editor::slotFileOpen()
{
    m_fileName = QFileDialog::getOpenFileName(this);
    QFile f(m_fileName);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open file %s: %s", qPrintable(m_fileName), qPrintable(f.errorString()));
        return;
    }

    m_fileLabel->setText(m_fileName.mid( m_fileName.lastIndexOf(QDir::separator()) + 1));

    QTextStream stream(&f);
    m_edit->setPlainText(stream.readAll());
    m_edit->document()->setModified(false);
    slotTextChanged();
}

void Editor::slotFileSave()
{
    QString candidate = QFileDialog::getSaveFileName(this, QString(), m_fileName);
    if (!candidate.isEmpty()) {
        QFile f(candidate);
        if( !f.open(QIODevice::WriteOnly) ) {
            qWarning("Couldn't open file %s: %s", qPrintable(candidate), qPrintable(f.errorString()));
            return;
        }
        m_fileName = candidate;
        QTextStream t(&f);
        t << m_edit->toPlainText();
        f.close();
        m_edit->document()->setModified(false);
        m_fileLabel->setText( m_fileName.mid( m_fileName.lastIndexOf(QDir::separator()) + 1 ) );
        slotTextChanged();
    } else {
        // Cancel, do nothing
    }
}

void Editor::slotFilePrint()
{
    QPrinter printer;
    QPrintDialog dialog(&printer);
    if( dialog.exec() ) {
        m_edit->document()->print( &printer );
        statusBar()->showMessage( "Printing completed", 2000 );
    } else
        statusBar()->showMessage( "Printing aborted", 2000 );
}

void Editor::slotQuit()
{
    if( m_edit->document()->isModified() ) {
        int r = QMessageBox::warning( this, "Save before quit",
                                      "The document is not saved",
                                      "Save", "Discard", "Cancel" );
        switch( r ) {
        case 0: // Save
            slotFileSave();
            break;
        case 1: // Discard
            break;
        case 2: // cancel
            return;
        }
    }
    qApp->quit();
}

void Editor::slotAbout()
{
    QMessageBox::about(this, "About Text Editor", "Super wiz-bang text editor");
}

void Editor::slotAboutQt()
{
    QMessageBox::aboutQt(this);
}

void Editor::slotTextChanged()
{
    bool modified = m_edit->document()->isModified();
    m_fileSave->setEnabled(modified);
    m_filePrint->setEnabled(modified);
}
