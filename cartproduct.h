
#ifndef CARTPRODUCT_H
#define CARTPRODUCT_H


#include "PRODUCT.h"
#include "customer.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QObject>
#include <QWidget>
#include "currentuser.h"


class CartProduct : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *v,*lout;
    QHBoxLayout *h[2];
    CUSTOMER *c;
    PRODUCT p;
    QSpacerItem *s[4];
    int quantity;
private slots:

    void button0();
    void button1();
    void button2();

signals:
    void changed();

public:
    QLabel *l[4];
    QPushButton *button[3];
    CartProduct(PRODUCT p, QVBoxLayout *lout,QWidget *parent =0);
    ~CartProduct();
};

#endif // CARTPRODUCT_H
