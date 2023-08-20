#include "passwordreset.h"
#include "ui_passwordreset.h"

passwordreset::passwordreset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordreset)
{
    ui->setupUi(this);
}

passwordreset::~passwordreset()
{
    delete ui;
}
