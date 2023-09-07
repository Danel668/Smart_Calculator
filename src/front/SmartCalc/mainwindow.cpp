#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_openbr, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_closebr, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(input_btns_clicked()));


    plot = new Plot();
    credit = new Credit();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_btns_clicked() {

    if (ui->result_show->text().length() <= 255) {
        QPushButton *pressed_btn = (QPushButton *)sender();
        QByteArray btn_text = pressed_btn->text().toLocal8Bit();
        const char *c_str = btn_text.data();

        if (ui->result_show->text() == '0' && !strpbrk(c_str, "+-/*.^")) {
            ui->result_show->setText("");
        }

        if (ui->result_show->text() == "Error") {
            ui->result_show->setText("");
        }

        ui->result_show->setText(ui->result_show->text() + pressed_btn->text());
        myStack.push(pressed_btn->text().length());
    }

}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->result_show->setText("0");
    while (!myStack.empty()) {
        myStack.pop();
     }
}


void MainWindow::on_pushButton_back_clicked()
{
    QString res = ui->result_show->text();
    if (!myStack.empty()) {
        res.chop(myStack.top());
        myStack.pop();
    }

    ui->result_show->setText(res);
    if (ui->result_show->text() == "") {
        ui->result_show->setText("0");
    }
}

void MainWindow::on_pushButton_equal_clicked()
{
    std::string str = ui->result_show->text().toStdString();

    const char *cstr = str.c_str();
    double x = 0;
    if (ui->x_show->text() != "") {
        x = ui->x_show->text().toDouble();
    }


    double res = 0;

    if (api_calculate(cstr, x, &res) == 1) {

        QString stringValue;
        stringValue.sprintf("%lf", res);

        ui->result_show->setText(stringValue);
        myStack.push(stringValue.size());
    }
    else {
        ui->result_show->setText("Error");
        myStack.push(5);
    }


}


void MainWindow::on_pushButton_graph_clicked()
{

    double x_start = -10;

    double const_x_start = -10;
    double x_end = 10;
    double y_start = -10;
    double y_end = 10;

    double h = 0.1;


    if (ui->Xmin->text() != "") {
        x_start = ui->Xmin->text().toDouble();
        const_x_start = ui->Xmin->text().toDouble();
    }

    if (ui->Xmax->text() != "") {
        x_end = ui->Xmax->text().toDouble();
    }

    if (ui->Ymin->text() != "") {
        y_start = ui->Ymin->text().toDouble();
    }

    if (ui->Ymax->text() != "") {
        y_end = ui->Ymax->text().toDouble();
    }

    if (x_start > x_end || x_start < -1000000 || x_end > 1000000) {
        x_start = -10;
        const_x_start = -10;
        x_end = 10;
    }

    if (y_start > y_end || y_start < -1000000 || y_end > 1000000) {
        y_start = -10;
        y_end = 10;
    }

    if (abs(x_start) + abs(x_end) > 10000) {
        h = (abs(x_start) + abs(x_end)) / 10000;
    }

    QVector<double> x,y;

    std::string str = ui->result_show->text().toStdString();

    const char *cstr = str.c_str();

    double y_res = 0;


    while (x_start <= x_end) {

        if (api_calculate(cstr, x_start, &y_res) == 1) {
            if (y_res >= y_start && y_res <= y_end) {
                x.push_back(x_start);
                y.push_back(y_res);
            }
        }
        x_start += h;
    }

    plot->draw_plot(x, y, const_x_start, x_end, y_start, y_end);

    plot->show();

}


void MainWindow::on_pushButton_kredit_clicked()
{
    credit->show();
}

