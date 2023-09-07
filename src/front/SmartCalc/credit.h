#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <math.h>

namespace Ui {
class Credit;
}

class Credit : public QWidget
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private slots:
    void on_calculateCredit_clicked();

private:
    Ui::Credit *ui;
};

#endif // CREDIT_H
