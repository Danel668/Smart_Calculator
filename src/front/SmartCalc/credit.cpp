#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_calculateCredit_clicked()
{
    ui->ResDopSum->setText("");
    ui->ResEveryMonth->setText("");
    ui->ResSum->setText("");

    double Sum_Of_Credit = 0;
    double Srok_Of_Credit = 0;
    double Per_Cent = 0;

    int type_Of_Credit = -1;

    if (ui->SumOfCredit->text() != "") {
        Sum_Of_Credit = ui->SumOfCredit->text().toDouble();
    }

    if (ui->Period->text() != "") {
        Srok_Of_Credit = ui->Period->text().toDouble();
    }

    if (ui->PerCent->text() != "") {
        Per_Cent = ui->PerCent->text().toDouble();
        Per_Cent /=100;
    }

    if (ui->anuitet->isChecked()){
        type_Of_Credit = 1;
    }
    if (ui->diferen->isChecked()) {
        type_Of_Credit = 2;
    }

    if (Sum_Of_Credit == 0 || Srok_Of_Credit == 0 || Per_Cent == 0 || type_Of_Credit == -1) return;

    if (type_Of_Credit == 1) {

        double m = Per_Cent / 12;

        double kaf = ((m*pow(1 + m, Srok_Of_Credit))/(pow(1+m,Srok_Of_Credit)-1));

        double everyMonth = Sum_Of_Credit * kaf;

        double res_summ = everyMonth * Srok_Of_Credit;

        double pereplata = res_summ - Sum_Of_Credit;

        QString stringValue;
        stringValue.sprintf("%lf", res_summ);

        ui->ResSum->setText(stringValue);

        QString stringValue1;
        stringValue1.sprintf("%lf", pereplata);

        ui->ResDopSum->setText(stringValue1);

        QString stringValue2;
        stringValue2.sprintf("%lf р", everyMonth);
        ui->ResEveryMonth->setText(stringValue2);

    }

    if (type_Of_Credit == 2) {


        double basic_payment = (Sum_Of_Credit / Srok_Of_Credit);
        double all_payment = 0;
        double ostatok = Sum_Of_Credit;

        int n = (int)Srok_Of_Credit;
        int count = 1;


        while (n > 0) {
            double forMonth = basic_payment + (ostatok*Per_Cent/12);
            ostatok -=forMonth;

            all_payment +=forMonth;

            QString stringValue;
            stringValue.sprintf("%d месяц: %lf р\n",count, forMonth);
            count++;

            ui->ResEveryMonth->setText(ui->ResEveryMonth->text() + stringValue);

            n--;
        }
        QString stringValue1;
        stringValue1.sprintf("%lf", all_payment);
        ui->ResSum->setText(stringValue1);

        double dop_payment = all_payment - Sum_Of_Credit;


        QString stringValue2;
        stringValue2.sprintf("%lf", dop_payment);
        ui->ResDopSum->setText(stringValue2);
    }


}

