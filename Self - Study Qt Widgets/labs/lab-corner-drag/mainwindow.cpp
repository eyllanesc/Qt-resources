/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pictureitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);
    if (qApp->arguments().contains("-test")) {
        PictureItem *pi = new PictureItem(":/apply.png");
        ui->graphicsView->scene()->addItem(pi);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_action_Open_Image_triggered()
{

    // build the extensions list
    QString extensions;
    foreach (const QByteArray & format, QImageReader::supportedImageFormats()) {
        extensions += "*." + format + " *." + format.toUpper() + " ";
    }

    // show the files dialog
    QSettings s;
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Select one or more pictures to add"), s.value("loadImagesDir").toString(), tr("Images (%1)").arg(extensions));

    if (!fileNames.isEmpty()) {
        addPictures(fileNames);
        QFileInfo path(fileNames[0]);
        s.setValue("loadImagesDir", path.absolutePath());
    }
}


void MainWindow::addPictures(QStringList fileNames) {
    foreach (QString f, fileNames) {
        PictureItem *item = new PictureItem(f);
        ui->graphicsView->scene()->addItem(item);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}
