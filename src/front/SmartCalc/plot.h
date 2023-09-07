#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"
#include <QWidget>
#include <QVector>

namespace Ui {
class Plot;
}

class Plot : public QWidget
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = nullptr);
    ~Plot();


public slots:
    void draw_plot(QVector<double> x, QVector<double> y, double Xs, double Xe, double Ys, double Ye);

private:
    Ui::Plot *ui;
};

#endif // PLOT_H
