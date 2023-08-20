#include "addproduct.h"
#include "ui_addproduct.h"

AddProduct::AddProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    seller=CurrentUser::GetSeller();

    ui->comboBox->addItem("Furniture");
    ui->comboBox->addItem("Men's wear");
    ui->comboBox->addItem("Women's wear");
    ui->comboBox->addItem("Kid's wear");
    ui->comboBox->addItem("Makeup");
    ui->comboBox->addItem("Laptops");
    ui->comboBox->addItem("Video games");
    ui->comboBox->addItem("Mobile phones");
    ui->comboBox->addItem("Tablets");
    ui->comboBox->addItem("Sports");
    ui->comboBox->addItem("Health and personal care");
    ui->comboBox->addItem("Pet supplies");
    ui->comboBox->addItem("Books");
}

void AddProduct::Clear() {
    ui->lineEdit_202->clear();
    ui->lineEdit_203->clear();
    ui->spinBox_200->clear();
    ui->lineEdit_204->clear();
    ui->comboBox->setCurrentIndex(-1);
    ui->label_212->clear();
    ui->label_209->clear();
    ui->label_206->clear();
    ui->label_204->clear();
    ui->label_202->clear();
    ui->label_212->clear();
    ui->label_250->clear();
}

AddProduct::~AddProduct()
{
    delete ui;
}

//lineedit 3 -> product name
//lineedit 2 -> product description
//lineedit 4 -> product price
//lineedit -> product path




void AddProduct::on_pushButton_200_clicked()
{
    bool valid = 1;
    bool priceValid=1;
    for(QChar i: ui->lineEdit_204->text())
    {
        if((i > '9' || i < '0') && i != '.')
        {
            priceValid = 0;
        }
    }
    if(!ui->lineEdit_203->text().size())
    {
        ui->label_202->setText("This field is required.");
        valid = 0;

    }
    else
    {
        ui->label_202->clear();
    }
    if(!ui->lineEdit_202->text().size())
    {
        ui->label_204->setText("This field is required.");
        valid = 0;
    }
    else
    {
        ui->label_204->clear();
    }
    if(!ui->lineEdit_204->text().size())
    {
        ui->label_206->setText("This field is required.");
        valid = 0;
    }
    else if(!priceValid)
    {
        ui->label_206->setText("Invalid price.");
    }
    else
    {
        ui->label_206->clear();
    }
    if(ui->comboBox->currentIndex() == -1)
    {
        ui->label_209->setText("This field is required.");
        valid = 0;
    }
    else
    {
        ui->label_209->clear();
    }

    if(path.isEmpty())
    {
        ui->label_212->setText("This field is required.");
        valid = 0;
    }
    else
    {
        ui->label_212->clear();
    }


    if(valid && priceValid)
    {
        seller->Addproduct(path,ui->lineEdit_202->text(),ui->lineEdit_203->text(),ui->spinBox_200->value(),ui->lineEdit_204->text().toFloat(),ui->comboBox->currentText());
        emit submited();
    }
}




void AddProduct::on_pushButton_250_clicked()
{
    path = QFileDialog::getOpenFileName(this,tr("Select Image"), QDir::homePath(),tr("Images (*.png *.jpg *.jpeg)"));
    if(!path.isEmpty())
    {
        ui->label_250->setText(path);
        ui->label_212->clear();
    }
}

