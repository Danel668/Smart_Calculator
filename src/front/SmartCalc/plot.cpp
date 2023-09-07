#include "plot.h"
#include "ui_plot.h"


Plot::Plot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plot)
{
    ui->setupUi(this);
}

Plot::~Plot()
{
    delete ui;
}


void Plot::draw_plot(QVector<double> x, QVector<double> y, double Xs, double Xe, double Ys, double Ye) {


    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x,y);

    ui->graph->xAxis->setLabel("x");
    ui->graph->yAxis->setLabel("y");
    ui->graph->xAxis->setRange(Xs, Xe);
    ui->graph->yAxis->setRange(Ys, Ye);

    ui->graph->replot();
}
