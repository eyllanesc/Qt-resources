/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>

class QPushButton;
class QLabel;

class ScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit ScrollArea(QWidget *parent = Q_NULLPTR);
    ~ScrollArea();
    
protected Q_SLOTS:
    void slotMore();
    void showRenders();

protected:
    void resizeEvent(QResizeEvent *event);
    
private:
    int m_mNumCheckboxes;
    QPushButton *m_more1;
    QPushButton *m_more2;
    QLabel *m_label1;
    QLabel *m_label2;
};

#endif // SCROLLAREA_H
