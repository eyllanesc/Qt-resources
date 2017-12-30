/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EDITOR_H
#define EDITOR_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>

class QAction;
class QLabel;

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = Q_NULLPTR);

protected Q_SLOTS:
    void slotFileOpen();
    void slotFileSave();
    void slotFilePrint();
    void slotQuit();

    void slotAbout();
    void slotAboutQt();

    void slotTextChanged();

protected:
    void closeEvent(QCloseEvent *) Q_DECL_OVERRIDE;

private:
    QAction   *m_fileSave;
    QAction   *m_filePrint;
    QTextEdit *m_edit;
    QLabel    *m_fileLabel;

    QString    m_fileName;
};

#endif // EDITOR_H
