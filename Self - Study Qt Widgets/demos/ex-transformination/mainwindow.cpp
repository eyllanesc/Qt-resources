/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "coordinatesystem.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transformdialog.h"
#include "transformationitem.h"
#include "animationqueue.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionMove_Up->setIcon(qApp->style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionMove_Down->setIcon(qApp->style()->standardIcon(QStyle::SP_ArrowDown));
    ui->actionPlay_All->setIcon(qApp->style()->standardIcon(QStyle::SP_MediaPlay));

    ui->transformListWidget->addAction(ui->actionEdit);
    ui->transformListWidget->addAction(ui->actionApply);
    ui->transformListWidget->addAction(ui->action_Add_Transform);
    ui->transformListWidget->addAction(ui->actionRemove);
    createItems();
}

void MainWindow::select(TransformationItem *item) {
    ui->transformListWidget->setItemSelected(item, true);
}

void MainWindow::createItems() {
    m_scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(m_scene);


    m_before = new CoordinateSystem;
    m_before->setText("Original");

    m_after = new CoordinateSystem;
    m_after->setText("Transformed");
    m_scene->addItem(m_after);
    m_after->moveBy(150,0);

    m_scene->addItem(m_before);
    m_animationQueue = new AnimationQueue(m_after, this);
    connect (m_animationQueue, &AnimationQueue::animating,
             this, &MainWindow::select);
    connect (m_animationQueue, &AnimationQueue::operationFinished,
             this, &MainWindow::finishedOperation);
}

void MainWindow::createTestObjects() {
    TransformationItem *i = new TransformationItem;
    i->scale(1.1, 1.1);
    ui->transformListWidget->addItem(i);

    i = new TransformationItem;
    i->rotate(20, Qt::ZAxis);
    ui->transformListWidget->addItem(i);

    i = new TransformationItem;
    i->translate(20, 20);
    ui->transformListWidget->addItem(i);

    i = new TransformationItem;
    i->shear(0, 0.1);
    ui->transformListWidget->addItem(i);


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

void MainWindow::on_action_Quit_triggered()
{
    qApp->quit();
}


void MainWindow::on_actionEdit_triggered()
{
    QListWidgetItem *item = ui->transformListWidget->currentItem();
    if (item == 0) return;
    TransformationItem *ti = dynamic_cast<TransformationItem*>(item);
    TransformDialog td(ti);
    td.exec();

}

void MainWindow::on_actionApply_triggered()
{
    QListWidgetItem *item = ui->transformListWidget->currentItem();
    if (item ==0) return;
    TransformationItem *ti = dynamic_cast<TransformationItem*>(item);
    m_animationQueue->add(ti);
}

void MainWindow::finishedOperation() {
    if (ui->actionCenter_After_Transform->isChecked())
        ui->graphicsView->centerOn(m_after);
}

void MainWindow::on_actionReverse_Apply_triggered()
{
    QListWidgetItem *item = ui->transformListWidget->currentItem();
    if (item ==0) return;
    TransformationItem *ti = dynamic_cast<TransformationItem*>(item);
    ti->reverseApply(m_after);
}


void MainWindow::on_actionRemove_triggered()
{
    QListWidgetItem *item = ui->transformListWidget->currentItem();
    if (item ==0) return;
    ui->transformListWidget->removeItemWidget(item);
    delete item;

}

void MainWindow::on_action_Add_Transform_triggered()
{
    TransformationItem *newItem = new TransformationItem;
    TransformDialog td(newItem);
    if (td.exec() == QDialog::Accepted && (newItem->operation() != TransformationItem::NONE)) {
        ui->transformListWidget->addItem(newItem);
    }
    else delete (newItem);
}

void MainWindow::on_actionReset_triggered()
{
    m_scene->removeItem(m_after);
    delete m_after;

    m_after = new CoordinateSystem;
    m_after->setText("Transformed");
    m_scene->addItem(m_after);
    m_after->moveBy(150,0);
    m_animationQueue->setItem(m_after);


//    ui->graphicsView->centerOn(m_after);
}

void MainWindow::on_actionZoom_in_triggered()
{
    ui->graphicsView->scale(1.2, 1.2);
    ui->graphicsView->centerOn(m_after);
}

void MainWindow::on_actionZoom_out_triggered()
{
    ui->graphicsView->scale(0.8, 0.8);
    ui->graphicsView->centerOn(m_after);
}


void MainWindow::on_actionPlay_All_triggered()
{
    int steps = ui->transformListWidget->count();
    for (int i=0; i<steps; ++i) {
        QListWidgetItem *item = ui->transformListWidget->item(i);
        TransformationItem *ti = dynamic_cast<TransformationItem*>(item);
        m_animationQueue->add(ti);
    }

}

void MainWindow::on_actionMove_Up_triggered()
{
    int row = ui->transformListWidget->currentIndex().row();
    if (row == 0) return;
    QListWidgetItem *item = ui->transformListWidget->takeItem(row);
    if (item == 0) return;
    row--;
    ui->transformListWidget->insertItem(row, item);
    ui->transformListWidget->setCurrentItem(item);

}

void MainWindow::on_actionMove_Down_triggered()
{
    int row = ui->transformListWidget->currentIndex().row();
    int count = ui->transformListWidget->count();
    if (row >= count -1) return;
    QListWidgetItem *item = ui->transformListWidget->takeItem(row);
    if (item == 0) return;
    row++;
    ui->transformListWidget->insertItem(row, item);
    ui->transformListWidget->setCurrentItem(item);

}


void MainWindow::on_transformListWidget_doubleClicked(QModelIndex)
{
    on_actionApply_triggered();
}
