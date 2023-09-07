#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>
#include "plot.h"
#include "credit.h"

extern "C" {
#include "../../calc_controlller.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::stack<int> myStack;

private slots:
    void input_btns_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_graph_clicked();

    void on_pushButton_kredit_clicked();

private:
    Ui::MainWindow *ui;
    Plot *plot;
    Credit *credit;
};
#endif // MAINWINDOW_H
