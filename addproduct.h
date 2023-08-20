#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include "currentuser.h"
#include "seller.h"
#include "QFileDialog"


namespace Ui {
class AddProduct;
}

class AddProduct : public QWidget
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    void Clear();
    ~AddProduct();
    SELLER* seller;
    QString path;

signals:
    void submited();

private slots:
    void on_pushButton_200_clicked();

    void on_pushButton_250_clicked();


private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
