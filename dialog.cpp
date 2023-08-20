#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ret = new QLabel();
    monthYear = new QLabel();
    QDate x;
        ui->calendarWidget->setMaximumDate(QDate(x.currentDate().year() - 18, x.currentDate().month(), x.currentDate().day()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    monthYear->setText((ui->calendarWidget->selectedDate().toString("MM/yy")));
    ret->setText((ui->calendarWidget->selectedDate().toString("dd/MM/yy")));
}


void Dialog::on_buttonBox_rejected()
{
    close();
}

