
#ifndef PRODUCTUI_H
#define PRODUCTUI_H


#include "product.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QObject>
#include <QWidget>


class ProductUI : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *l1[5];

    PRODUCT p;

private slots:
    void BClicked();

signals:
    void VProduct();

public:
    QPushButton *button;
    ProductUI(PRODUCT p, QWidget *parent = 0);
    ~ProductUI();
};

#endif // PRODUCTUI_H

