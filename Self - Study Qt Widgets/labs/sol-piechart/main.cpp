/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "piechart.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PieChart chart;
    chart.setValue("Germany", 80);
    chart.setValue("Italy", 61);
    chart.setValue("Sweden", 10);
    chart.setValue("Norway", 5);
    chart.show();
    return app.exec();
}
