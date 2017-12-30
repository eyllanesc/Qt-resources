/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "transformdialog.h"
#include "ui_transformdialog.h"
#include "transformationitem.h"

TransformDialog::TransformDialog(TransformationItem* ti, QWidget *parent) :
    QDialog(parent),  ui(new Ui::TransformDialog), m_item(ti)
{
    ui->setupUi(this);
    ui->operationCombo->addItems(ti->operations());
    updateUi();
}

void TransformDialog::updateUi() {
    if (m_item != 0) {
        QTransform t = m_item->matrix();
        ui->m11->setValue(t.m11());
        ui->m12->setValue(t.m12());
        ui->m13->setValue(t.m13());
        ui->m21->setValue(t.m21());
        ui->m22->setValue(t.m22());
        ui->m23->setValue(t.m23());
        ui->m31->setValue(t.m31());
        ui->m32->setValue(t.m32());
        ui->m33->setValue(t.m33());

        ui->operationCombo->setCurrentIndex(m_item->operation());
        ui->angleSpinBox->setValue(m_item->angle());
        ui->axisCombo->setCurrentIndex(m_item->axis());
        ui->horizontalSpinbox->setValue(m_item->x());
        ui->verticalSpinbox->setValue(m_item->y());
    }

    on_operationCombo_activated(0);

}

void TransformDialog::accept() {
    int idx = ui->operationCombo->currentIndex();
    QTransform t;
    switch (idx) {
        case TransformationItem::ROTATE:
            m_item->rotate(ui->angleSpinBox->value(), (Qt::Axis)ui->axisCombo->currentIndex());
            break;
        case TransformationItem::SHEAR:
            m_item->shear(ui->horizontalSpinbox->value(), ui->verticalSpinbox->value());
            break;
        case TransformationItem::TRANSLATE:
            m_item->translate(ui->horizontalSpinbox->value(), ui->verticalSpinbox->value());
            break;
        case TransformationItem::SCALE:
            m_item->scale(ui->horizontalSpinbox->value(), ui->verticalSpinbox->value());
            break;
        case TransformationItem::MATRIX:

            t.setMatrix(ui->m11->value(), ui->m12->value(), ui->m13->value(),
                        ui->m21->value(), ui->m22->value(), ui->m23->value(),
                        ui->m31->value(), ui->m32->value(), ui->m33->value());
            m_item->setMatrix(t);
            break;
        default:
            m_item->setOperation(TransformationItem::NONE);
    }
    QDialog::accept();
}

TransformDialog::~TransformDialog()
{
    delete ui;
}

void TransformDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void TransformDialog::on_operationCombo_activated(int )
{
    QString value = ui->operationCombo->currentText();
    QStringList xyops= QStringList() << "SHEAR" << "SCALE" << "TRANSLATE";
    ui->matrixGroup->setVisible(value == "MATRIX");
    ui->rotateGroup->setVisible(value== "ROTATE");
    ui->xyArgumentGroup->setVisible(xyops.contains(value));
    // updateGeometry();
    adjustSize();
}


