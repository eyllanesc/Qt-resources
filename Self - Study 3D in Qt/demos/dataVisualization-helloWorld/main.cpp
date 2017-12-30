#include <QApplication>
#include <Q3DBars>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q3DBars graph;
    graph.setGeometry(0, 0, 640, 480);
    QBarDataProxy *newProxy = new QBarDataProxy;
    QBarDataArray *dataArray = new QBarDataArray;
    dataArray->reserve(10);
    for (int i = 0; i < 10; i++) {
        QBarDataRow *dataRow = new QBarDataRow(5);
        for (int j = 0; j < 5; j++)
            (*dataRow)[j].setValue(0.7 * i + 2.6 * j);
        dataArray->append(dataRow);
    }     newProxy->resetArray(dataArray);
    QBar3DSeries *series = new QBar3DSeries(newProxy);
    graph.addSeries(series);

    graph.show();
    return a.exec();
}

