/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TRANSFORMDIALOG_H
#define TRANSFORMDIALOG_H

#include <QDialog>
class TransformationItem;
namespace Ui {
    class TransformDialog;
}

/** An editor for TransformationItem objects */
class TransformDialog : public QDialog {
    Q_OBJECT
public:
    TransformDialog(TransformationItem* item, QWidget *parent = Q_NULLPTR);
    ~TransformDialog();

protected:
    void changeEvent(QEvent *e) Q_DECL_OVERRIDE;
protected Q_SLOTS:
    void accept() Q_DECL_OVERRIDE;
    void updateUi();
private:
    Ui::TransformDialog *ui;
    TransformationItem *m_item;

private Q_SLOTS:
    void on_operationCombo_activated(int index);
};

#endif // TRANSFORMDIALOG_H
