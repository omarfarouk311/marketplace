
#ifndef CARTCONTAINER_H
#define CARTCONTAINER_H

#include "PRODUCT.h"
#include "cartproduct.h"
#include "customer.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QObject>
#include <QWidget>
#include "currentuser.h"


class CartContainer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *lout;
    QSpacerItem *s;
    vector<CartProduct*> cp;
private slots:
    void ChangedReceiver();
signals:
    void recalculate();

public:
    CartContainer(QVBoxLayout *l, QWidget *parent = 0);

    ~CartContainer();

};





#endif // CARTCONTAINER_H
