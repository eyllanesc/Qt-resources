/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef FILECHOOSER_H
#define FILECHOOSER_H

#include <QtWidgets>

class FileChooser : public QWidget
{
    Q_OBJECT

    Q_ENUMS(Mode)
    Q_PROPERTY(Mode mode READ mode WRITE setMode)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

public:
    FileChooser(QWidget *parent = Q_NULLPTR);

    enum Mode { File, Directory };

    QString fileName() const;
    Mode mode() const;

public Q_SLOTS:
    void setFileName(const QString &fileName);
    void setMode(Mode mode);

Q_SIGNALS:
    void fileNameChanged(const QString &fileName);

private Q_SLOTS:
    void chooseFile();

private:
    QLineEdit *m_lineEdit;
    QPushButton *m_button;
    Mode m_mode;

};

#endif // FILECHOOSER_H
